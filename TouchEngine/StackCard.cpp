//
//  StackCard.cpp
//  TouchEngine
//
//  Created by geminileft on 7/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "StackCard.h"
#include "PlayingCard.h"

StackCard::StackCard(PlayingCard* card) : TEComponentStack(Card), mMoving(false), mPreviousStack(NULL), mMoveToFoundation(false) {
    setPlayingCard(card);
    addEventSubscription(EVENT_TOUCH_STARTED, new TEEventListener<StackCard>(this, &StackCard::touchStartedListener));
    addEventSubscription(EVENT_TOUCH_ENDED, new TEEventListener<StackCard>(this, &StackCard::touchEndedListener));
    addEventSubscription(EVENT_REJECT_MOVE, new TEEventListener<StackCard>(this, &StackCard::rejectMoveListener));
    addEventSubscription(EVENT_PRE_MOVE_TO_FOUNDATION, new TEEventListener<StackCard>(this, &StackCard::preMoveToFoundationListener));
}

void StackCard::update() {
    if (mMoving) {
        adjustStackPositions();			
    }
}

int StackCard::getStackOffset(bool isFirst) {
    return CARD_OFFSET;
}

void StackCard::touchStartedListener() {
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

void StackCard::touchEndedListener() {
	mMoving = false;
	evaluate();
}

bool StackCard::doesAccept(TEComponentStack* stack) {
	return true;
}

void StackCard::rejectMoveListener() {
	StackCard* component = this;
	if (mPreviousStack != NULL) {
		mPreviousStack->pushStack(component);
	} else {
		component->mParent->position.x = mPreviousPosition.x;
		component->mParent->position.y = mPreviousPosition.y;
		adjustStackPositions();
	}
}

void StackCard::preMoveToFoundationListener() {
	mMoveToFoundation = true;
	mParent->invokeEvent(EVENT_MOVE_TO_FOUNDATION);
}

void StackCard::resetMoveToFoundation() {
	mMoveToFoundation = false;
}

bool StackCard::isMoveToFoundation() {
	return mMoveToFoundation;
}
