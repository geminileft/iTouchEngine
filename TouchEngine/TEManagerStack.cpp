//
//  TEManagerStack.cpp
//  TouchEngine
//
//  Created by geminileft on 7/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TEManagerStack.h"

static TEManagerStack* mSharedInstance = NULL;
//private final int ACE_STACK_COUNT = 4;

TEManagerStack* TEManagerStack::sharedManager() {
    if (mSharedInstance == NULL) {
        mSharedInstance = new TEManagerStack();
    }
    return mSharedInstance;
}

void TEManagerStack::moveComponentToTop(TEComponent* component) {}

void TEManagerStack::update() {
/*
    TEComponentContainer components = getComponents();
    if (!components.isEmpty()) {
        final int size = components.size();
        for(int i = 0;i < size;++i) {
            TEComponentStack component = (TEComponentStack)components.get(i);
            component.update();
            if (component.isEvaluateReady) {
                TEComponentStack dropStack = getDropStack(component);
                if (dropStack == null) {
                    component.parent.invokeEvent(Event.EVENT_REJECT_MOVE);
                } else {
                    component.parent.invokeEvent(Event.EVENT_ACCEPT_MOVE);
                    dropStack.pushStack(component);
                }
                component.resetEvaluate();
            }
        }		
    }
*/
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
	
	private TEComponentStack getDropStack(TEComponentStack component) {
		TEComponentStack returnStack = null;
		TEComponentContainer components = getComponents();
		if (!components.isEmpty()) {
			final int size = components.size();
		    for(int i = 0;i < size;++i) {
		    	TEComponentStack stack = (TEComponentStack)components.get(i);
		    	if ((stack.isTopStack()) && component.doesOverlap(stack) && stack.getRootStack().doesAccept(component)) {
		    		returnStack = stack;
		    		break;
		    	}
		    }
		}
		return returnStack;
	}
	
	public TEComponent.EventListener getMoveToAceStackListener() {
		return mMoveToFoundationListener;
	}
	
	public void addAceStack(StackAceCell aceStack) {
		mAceStacks[mAceStackCount] = aceStack;
		++mAceStackCount;
	}
}
 */
