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

void TEManagerInput::update() {}

TEManagerInput* TEManagerInput::sharedManager() {
    if (mSharedInstance == NULL) {
        mSharedInstance = new TEManagerInput();
    }
    return mSharedInstance;
}

void TEManagerInput::beginTouch(TEInputTouch* touch) {
    //mTouches.put(touch.getPointerId(), touch);
}


/*
	private HashMap<Integer, TEInputTouch> mTouches;
	
	public TEManagerInput() {
		mTouches = new HashMap<Integer, TEInputTouch>();
	}
    
	public void moveTouch(TEInputTouch touch) {
		if (mTouches.containsKey(touch.getPointerId())) {
			mTouches.get(touch.getPointerId()).getEndPoint().update(touch.getEndPoint());
		}
	}
    
	public void endTouch(TEInputTouch touch) {
		if (mTouches.containsKey(touch.getPointerId())) {
			mTouches.get(touch.getPointerId()).endTouch(touch.getEndPoint());
		}
	}
    
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