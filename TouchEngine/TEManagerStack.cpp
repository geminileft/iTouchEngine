#include "TEManagerStack.h"
#include "TEComponentStack.h"
#include "StackAceCell.h"
#include "StackTableCell.h"
#include "StackCard.h"
#include "PlayingCard.h"
#include "TEGameObject.h"
#include "TEEventListener.h"

static TEManagerStack* mSharedInstance = NULL;
static int mAceStackCount = 0;
static int mTableStackCount = 0;

TEManagerStack* TEManagerStack::sharedManager() {
    if (mSharedInstance == NULL) {
        mSharedInstance = new TEManagerStack();
    }
    return mSharedInstance;
}

void TEManagerStack::moveComponentToTop(TEComponent* component) {}

void TEManagerStack::update() {
    TEComponentContainer components = getComponents();
    if (!components.empty()) {
		TEComponentContainer::iterator iterator;
        for(iterator = components.begin();iterator != components.end();++iterator) {
            TEComponentStack* component = (TEComponentStack*)(*iterator);
            component->update();
            if (component->mIsEvaluateReady) {
                TEComponentStack* dropStack = getDropStack(component);
                if (dropStack == NULL) {
                    component->mParent->invokeEvent(EVENT_REJECT_MOVE);
                } else {
                    component->mParent->invokeEvent(EVENT_ACCEPT_MOVE);
                    dropStack->pushStack(component);
                }
                component->resetEvaluate();
            }
        }		
    }
}

TEComponentStack* TEManagerStack::getDropStack(TEComponentStack* component) {
	TEComponentStack* returnStack = NULL;
	TEComponentContainer components = getComponents();
	if (!components.empty()) {
		TEComponentContainer::iterator iterator;
		for(iterator = components.begin();iterator != components.end();++iterator) {
			TEComponentStack* stack = (TEComponentStack*)(*iterator);
			if ((stack->isTopStack()) && component->doesOverlap(stack) && stack->getRootStack()->doesAccept(component)) {
				returnStack = stack;
				break;
			}
		}
	}
	return returnStack;
}

void TEManagerStack::addAceStack(StackAceCell* aceStack) {
	mAceStacks[mAceStackCount] = aceStack;
	++mAceStackCount;
}

void TEManagerStack::moveToAceStack() {
	TEComponentContainer components = getComponents();
	StackCard* card = NULL;
	for (TEComponentContainer::iterator iterator = components.begin();iterator != components.end();++iterator) {
		if (((StackCard*)*iterator)->isMoveToFoundation()) {
			card = (StackCard*)(*iterator);
			break;
		}
	}
	
	if (card != NULL) {
		PlayingCard* playingCard = card->getPlayingCard();
		for(int i = 0;i < ACE_STACK_COUNT;++i) {
			if (mAceStacks[i]->getChildStack() == NULL) {
				if (playingCard->getFaceValue() == Ace) {
					if (card->getParentStack() != NULL) {
						card->getParentStack()->popStack(card);
					}
					mAceStacks[i]->pushStack(card);
                    card->mParent->invokeEvent(EVENT_ACCEPT_MOVE);
					break;
				}
			} else {
				StackCard* topCard = (StackCard*)mAceStacks[i]->getChildStack();
				while (topCard->getChildStack() != NULL) {
					topCard = (StackCard*)topCard->getChildStack();
				}
				PlayingCard* topPlayingCard = topCard->getPlayingCard();
				if (playingCard->getSuit() == topPlayingCard->getSuit() && playingCard->getFaceValue() == topPlayingCard->getFaceValue() + 1) {
					mAceStacks[i]->pushStack(card);
                    card->mParent->invokeEvent(EVENT_ACCEPT_MOVE);
					break;
				}
			}
		}
		card->resetMoveToFoundation();
	}
}

TEEventListenerBase* TEManagerStack::getMoveToAceStackListener() {
	return new TEEventListener<TEManagerStack>(this, &TEManagerStack::moveToAceStack);
}

void TEManagerStack::addTableStack(StackTableCell* tableStack) {
	mTableStacks[mTableStackCount] = tableStack;
	++mTableStackCount;
}

TEEventListenerBase* TEManagerStack::getTouchAcceptListener() {
	return new TEEventListener<TEManagerStack>(this, &TEManagerStack::touchAcceptListener);
}

void TEManagerStack::touchAcceptListener() {
	bool good = true;
	for (int i = 0;i < TABLE_STACK_COUNT;++i) {
		StackTableCell* stack = mTableStacks[i];
		if (!stack->getClear()) {
			StackCard* card = (StackCard*)stack->getChildStack();
			if (card == NULL) {
				stack->setClear();
			} else {
				PlayingCard* playingCard = card->getPlayingCard();
				while (card->getChildStack() != NULL) {
					card = (StackCard*)card->getChildStack();
					PlayingCard* childPlayingCard = card->getPlayingCard();
					good = (playingCard->getFaceValue() >= childPlayingCard->getFaceValue());
					if (!good) {
						return;
					}
				}
				stack->setClear();
			}
		}
	}
}
