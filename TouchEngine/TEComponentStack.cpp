//
//  TEComponentStack.cpp
//  TouchEngine
//
//  Created by geminileft on 7/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TEComponentStack.h"

static int mOpenFreeCellCount = 0;
static int mOpenTableCellCount = 0;

TEComponentStack::TEComponentStack(StackType stackType) : mChildStack(NULL), mParentStack(NULL) {
    mStackType = stackType;
}

void TEComponentStack::setPlayingCard(PlayingCard* card) {
    mCard = card;
}

void TEComponentStack::pushStack(TEComponentStack* stack) {
    mChildStack = stack;
    stack->setParentStack(this);
    mTopStack = false;
    adjustStackPositions();
}

void TEComponentStack::setParentStack(TEComponentStack* stack) {
    mParentStack = stack;
}

void TEComponentStack::adjustStackPositions() {
    TEComponentStack* stack = getRootStack();
    int offset = stack->getStackOffset(true);
    const int newOffset = stack->getStackOffset(false);
    TEGameObject* rootParent = stack->mParent;
    TEPoint position;
    position.x = rootParent->position.x;
    position.y = rootParent->position.y;
    while (stack->getChildStack() != NULL) {
        position.y -= offset;
        stack = stack->getChildStack();
        stack->mParent->position.x = position.x;
        stack->mParent->position.y = position.y;
        offset = newOffset;
    }
}

TEComponentStack* TEComponentStack::getRootStack() {
    TEComponentStack* rootStack;
    if (mParentStack != NULL) {
        rootStack = mParentStack;
        while (rootStack->getParentStack() != NULL) {
            rootStack = rootStack->getParentStack();
        }
    } else {
        rootStack = this;
    }
    return rootStack;
}

TEComponentStack* TEComponentStack::getParentStack() {
    return mParentStack;
}

TEComponentStack* TEComponentStack::getChildStack() {
    return mChildStack;
}

PlayingCard* TEComponentStack::getPlayingCard() {
	return mCard;
}

int TEComponentStack::getOpenTableCellCount() {
	return mOpenTableCellCount;
}
int TEComponentStack::getOpenFreeCellCount() {
	return mOpenFreeCellCount;
}

int TEComponentStack::getPickupCount(int freeCellCount, int tableCellCount) {
	int pickupCount = freeCellCount + 1;
	for (int i = 0;i < tableCellCount;++i) {
		pickupCount += i + 1 + freeCellCount;
	}
	return pickupCount;
}

void TEComponentStack::popStack(TEComponentStack* stack) {
	if (stack == mChildStack) {
		stack->setParentStack(NULL);
		mChildStack = NULL;
		mTopStack = true;
	}
}

/*
	
	public StackType getStackType() {
		return mStackType;
	}
	
	public final boolean doesOverlap(TEComponentStack stack) {
		boolean returnValue = false;
		if (!isParentOf(stack)) {
			TEUtilRect parentRect = new TEUtilRect(parent.position, parent.size);
			TEGameObject stackParent = stack.parent;
			TEUtilRect stackRect = new TEUtilRect(stackParent.position, stackParent.size);
			returnValue = parentRect.overlaps(stackRect);
		}
		return returnValue;
	}
	
	public final boolean isTopStack() {
		return mTopStack;
	}
	
	public final TEComponentStack getChildStack() {
		return mChildStack;
	}
	
	public final void evaluate() {
		isEvaluateReady = true;
	}
	
	public final void resetEvaluate() {
		isEvaluateReady = false;
	}
	
	private final boolean isParentOf(TEComponentStack stack) {
		boolean returnValue = (stack == this);
		TEComponentStack childStack = this.getChildStack();
		while (!returnValue && (childStack != null)) {
			returnValue = (stack == childStack);
			childStack = childStack.getChildStack();
		}
		return returnValue;
	}
    
}
*/
