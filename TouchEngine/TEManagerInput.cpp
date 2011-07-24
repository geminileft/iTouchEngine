//
//  TEManagerInput.cpp
//  TouchEngine
//
//  Created by geminileft on 7/22/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TEManagerInput.h"
#include "TEInputTouch.h"

static TEManagerInput* mSharedInstance = NULL;

TEManagerInput* TEManagerInput::sharedManager() {
    if (mSharedInstance == NULL) {
        mSharedInstance = new TEManagerInput();
    }
    return mSharedInstance;
}

void TEManagerInput::beginTouch(TEInputTouch* touch) {
    mTouches[touch->getPointerId()] = touch;
}

void TEManagerInput::moveTouch(TEInputTouch* touch) {
    std::map<int, TEInputTouch*>::iterator iterator = mTouches.find(touch->getPointerId());
    if (iterator != mTouches.end()) {
        iterator->second->setEndPoint(touch->getEndPoint());
    }
}

void TEManagerInput::endTouch(TEInputTouch* touch) {
    std::map<int, TEInputTouch*>::iterator iterator = mTouches.find(touch->getPointerId());
    if (iterator != mTouches.end()) {
        iterator->second->endTouch(touch->getEndPoint());
    }
}

/*    
	public 	HashMap<Integer, TEInputTouch> getInputState() {
		HashMap<Integer, TEInputTouch> touchState = new HashMap<Integer, TEInputTouch>();
		Collection<TEInputTouch> collection = mTouches.values();
		TEInputTouch addTouch;
		final Iterator<TEInputTouch> iterator = collection.iterator();
		while (iterator.hasNext()) {
			addTouch = iterator.next().copy();
			touchState.put(addTouch.getPointerId(), addTouch);
			if (addTouch.ended()) {
				mTouches.remove(addTouch.getPointerId());
			} else {
				mTouches.get(addTouch.getPointerId()).reset();
			}
		}
		return touchState;
	}
}
*/