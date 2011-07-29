//
//  StackCard.cpp
//  TouchEngine
//
//  Created by geminileft on 7/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "StackCard.h"
#include "PlayingCard.h"

StackCard::StackCard(PlayingCard* card) : TEComponentStack(Card), mMoving(false) {
    setPlayingCard(card);
	TEEventListener<StackCard>* touchStartedListener = new TEEventListener<StackCard>(this, &StackCard::moveToTopListener);
    addEventSubscription(EVENT_TOUCH_STARTED, touchStartedListener);
    //addEventSubscription(Event.EVENT_TOUCH_ENDED, mTouchEndedListener);
    //addEventSubscription(Event.EVENT_REJECT_MOVE, mRejectMoveListener);
}

void StackCard::update() {
    /*
    if (mMoving) {
        adjustStackPositions();			
    }
     */
}

int StackCard::getStackOffset(bool isFirst) {
    return CARD_OFFSET;
}

void StackCard::moveToTopListener() {
	bool isGoodStack = true;
	TEComponentStack* component = this;
	int cardCount = 1;
	TEComponentStack* childStack = component->getChildStack();
	if (childStack != NULL) {
		PlayingCard* oldCard = component->getPlayingCard();
		while (childStack != NULL) {
			PlayingCard* card = childStack->getPlayingCard();
			++cardCount;
			if (!oldCard->canStack(card)) {
				isGoodStack = false;
				break;
			}
			oldCard = card;
			childStack = childStack->getChildStack();
		}
	}
	if (isGoodStack && (cardCount <= getPickupCount(TEComponentStack::getOpenFreeCellCount(), TEComponentStack::getOpenTableCellCount()))) {
		mParent->invokeEvent(EVENT_TOUCH_ACCEPT);
		mMoving = true;
		TEGameObject* parent = component->mParent;
		mPreviousPosition.x = parent->position.x;
		mPreviousPosition.y = parent->position.y;
		mPreviousStack = component->getParentStack();
		if (mPreviousStack != NULL) {
			mPreviousStack->popStack(component);				
		}
		parent->invokeEvent(EVENT_MOVE_TO_TOP);
		childStack = component->getChildStack();
		while (childStack != NULL) {
			childStack->mParent->invokeEvent(EVENT_MOVE_TO_TOP);
			childStack = childStack->getChildStack();
		}
	} else {
		mParent->invokeEvent(EVENT_TOUCH_REJECT);
	}
}

/*
	private TEComponent.EventListener mTouchEndedListener = new TEComponent.EventListener() {
		
		public void invoke() {
			mMoving = false;
			StackCard.this.evaluate();
		}
	};
	
	private TEComponent.EventListener mRejectMoveListener = new TEComponent.EventListener() {
		
		public void invoke() {
			StackCard component = StackCard.this;
			if (mPreviousStack != null) {
				mPreviousStack.pushStack(component);
			} else {
				component.parent.position = new Point(mPreviousPosition.x, mPreviousPosition.y);
				adjustStackPositions();
			}
		}
	};
	
	@Override
	public final boolean doesAccept(TEComponentStack stack) {
		return true;
	}
}
*/