//
//  StackCard.cpp
//  TouchEngine
//
//  Created by geminileft on 7/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "StackCard.h"

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

StackCard::StackCard(PlayingCard* card) : TEComponentStack(Card) {
    setPlayingCard(card);
    //addEventSubscription(Event.EVENT_TOUCH_STARTED, mTouchStartedListener);
    //addEventSubscription(Event.EVENT_TOUCH_ENDED, mTouchEndedListener);
    //addEventSubscription(Event.EVENT_REJECT_MOVE, mRejectMoveListener);
}


/*
	private boolean mMoving = false;
	private Point mPreviousPosition;
	private TEComponentStack mPreviousStack;
	
	private TEComponent.EventListener mTouchStartedListener = new TEComponent.EventListener() {
		
		public void invoke() {
			boolean isGoodStack = true;
			TEComponentStack component = StackCard.this;
			int cardCount = 1;
			TEComponentStack childStack = component.getChildStack();
			if (childStack != null) {
				PlayingCard oldCard = component.getPlayingCard();
				while (childStack != null) {
					PlayingCard card = childStack.getPlayingCard();
					++cardCount;
					if (!oldCard.canStack(card)) {
						isGoodStack = false;
						break;
					}
					oldCard = card;
					childStack = childStack.getChildStack();
				}
			}
			if (isGoodStack && (cardCount <= getPickupCount(TEComponentStack.openFreeCellCount, TEComponentStack.openTableCellCount))) {
				parent.invokeEvent(Event.EVENT_TOUCH_ACCEPT);
				mMoving = true;
				TEGameObject parent = component.parent;
				mPreviousPosition = new Point(parent.position.x, parent.position.y);
				mPreviousStack = component.getParentStack();
				if (mPreviousStack != null) {
					mPreviousStack.popStack(component);				
				}
				parent.invokeEvent(Event.EVENT_MOVE_TO_TOP);
				childStack = component.getChildStack();
				while (childStack != null) {
					childStack.parent.invokeEvent(Event.EVENT_MOVE_TO_TOP);
					childStack = childStack.getChildStack();
				}
			} else {
				parent.invokeEvent(Event.EVENT_TOUCH_REJECT);
			}
		}
	};
	
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