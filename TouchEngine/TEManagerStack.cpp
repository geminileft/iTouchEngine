//
//  TEManagerStack.cpp
//  TouchEngine
//
//  Created by geminileft on 7/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TEManagerStack.h"
#include "TEComponentStack.h"
#include "StackAceCell.h"

static TEManagerStack* mSharedInstance = NULL;
static int mAceStackCount = 0;

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
/*
	private TEComponent.EventListener mMoveToFoundationListener = new TEComponent.EventListener() {
		
		public void invoke() {
			for(int i = 0;i < ACE_STACK_COUNT;++i) {
				if (mAceStacks[i].getChildStack() == null) {
					Log.v("TEManagerStack.mMoveToFoundationListener.invoke", "lol");
				}
			}
			Log.v("TEManagerStack.mMoveToAceStack.invoke", "I am called");
		}
	};        

	public TEComponent.EventListener getMoveToAceStackListener() {
		return mMoveToFoundationListener;
	}
*/
