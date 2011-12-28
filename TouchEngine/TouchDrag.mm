//
//  TouchDrag.cpp
//  TouchEngine
//
//  Created by geminileft on 7/23/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TouchDrag.h"
#include "TEManagerTime.h"
#include "TEGameObject.h"
#include "TEEventListener.h"

TouchDrag::TouchDrag() : TEComponentTouch(), mTouch(NULL), mTouchValid(false) {
	TEEventListener<TouchDrag>* touchAcceptListener = new TEEventListener<TouchDrag>(this, &TouchDrag::touchAcceptListener);
	TEEventListener<TouchDrag>* touchRejectListener = new TEEventListener<TouchDrag>(this, &TouchDrag::touchRejectListener);
    addEventSubscription(EVENT_TOUCH_ACCEPT, touchAcceptListener);
    addEventSubscription(EVENT_TOUCH_REJECT, touchRejectListener);
}

void TouchDrag::update() {
    if (mTouchValid && (mTouch != NULL)) {
        float x = mTouch->getEndPoint().x + mTouchOffset.x;
        float y = mTouch->getEndPoint().y + mTouchOffset.y;
        if (mTouch->ended()) {

			mLastUpTime = TEManagerTime::currentTime();
			long elapsedTime = mLastUpTime - mStartTime;
			if (elapsedTime < TAP_DOWN_THRESHOLD_MS) {
				++mTapCount;
				switch(mTapCount) {
					case 1:
						break;
					case 2:
						mParent->invokeEvent(EVENT_PRE_MOVE_TO_FOUNDATION);
						break;
				}
			} else {
				mTapCount = 0;
				mParent->invokeEvent(EVENT_TOUCH_ENDED);
			}
            mTouch = NULL;
            mTouchValid = false;
        }
        mParent->position.x = x;
        mParent->position.y = y;
    }
}

bool TouchDrag::addTouch(TEInputTouch* touch) {
    bool added = false;
    if (mTouch == NULL) {

		mStartTime = TEManagerTime::currentTime();
		long elapsedTime = mStartTime - mLastUpTime;
		if (elapsedTime > TAP_UP_THRESHOLD_MS) {
			mTapCount = 0;
		}

        added = true;
        mTouch = touch->copy();
        TEPoint pt = mParent->position;
        mTouchOffset.x = pt.x - touch->getStartPoint().x;
        mTouchOffset.y = pt.y - touch->getStartPoint().y;
		getManager()->moveComponentToTop(this);
        mParent->invokeEvent(EVENT_TOUCH_STARTED);
    }
    return added;
}

bool TouchDrag::updateTouch(TEInputTouch* touch) {
    bool returnValue = false;
    if (mTouch != NULL) {
        mTouch = touch->copy();
        returnValue = true;
    }
    return returnValue;
}

void TouchDrag::touchAcceptListener() {
	mTouchValid = true;
}

void TouchDrag::touchRejectListener() {
	mTouchValid = false;
	mTouch = NULL;	
}
