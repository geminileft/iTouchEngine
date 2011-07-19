//
//  TEComponentStack.cpp
//  TouchEngine
//
//  Created by geminileft on 7/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TEComponentStack.h"

/*
	public TEComponentStack(StackType stackType) {
		super();
		mStackType = stackType;
	}
	
	public StackType getStackType() {
		return mStackType;
	}
	
	public void pushStack(TEComponentStack stack) {
		mChildStack = stack;
		stack.setParentStack(this);
		mTopStack = false;
		adjustStackPositions();
	}
	
	public void popStack(TEComponentStack stack) {
		if (stack == mChildStack) {
			stack.setParentStack(null);
			mChildStack = null;
			mTopStack = true;
		}
	}
	
	public final void setParentStack(TEComponentStack stack) {
		mParentStack = stack;
	}
	
	public final TEComponentStack getParentStack() {
		return mParentStack;
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
	
	public final void adjustStackPositions() {
		TEComponentStack stack = getRootStack();
		int offset = stack.getStackOffset(true);
		final int newOffset = stack.getStackOffset(false);
		TEGameObject rootParent = stack.parent;
		Point position = new Point(rootParent.position.x, rootParent.position.y);
		while (stack.getChildStack() != null) {
			position.y -= offset;
			stack = stack.getChildStack();
			stack.parent.position = new Point(position.x, position.y);
			offset = newOffset;
		}
	}
	
	public TEComponentStack getRootStack() {
		TEComponentStack rootStack;
		if (mParentStack != null) {
			rootStack = mParentStack;
			while (rootStack.getParentStack() != null) {
				rootStack = rootStack.getParentStack();
			}
		} else {
			rootStack = this;
		}
		return rootStack;
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
    
	public void setPlayingCard(PlayingCard card) {
		mCard = card;
	}
	
	public PlayingCard getPlayingCard() {
		return mCard;
	}
	
	public final int getPickupCount(int freeCellCount, int tableCellCount) {
		int pickupCount = freeCellCount + 1;
		for (int i = 0;i < tableCellCount;++i) {
			pickupCount += i + 1 + freeCellCount;
		}
		return pickupCount;
	}
}
*/
