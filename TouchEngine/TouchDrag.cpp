//
//  TouchDrag.cpp
//  TouchEngine
//
//  Created by geminileft on 7/23/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TouchDrag.h"

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
            //mTouchHandler.endTouch(mTouch);
            mParent->invokeEvent(EVENT_TOUCH_ENDED);
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
        //mTouchHandler->startTouch(touch);
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

/*
public class TouchDrag extends TEComponentTouch {
	private TETouchHandler mTouchHandler = new TETouchHandler();
	//private int mTapCount;
	public enum TouchAction {
		NONE
		, TAP
		, DOUBLE_TAP
	}
    
	private final class TETouchHandler {
		private long mStartTime;
		private int mTapCount;
		private long mLastUpTime;
		static final int TAP_DOWN_THRESHOLD_MS = 130;
		static final int TAP_UP_THRESHOLD_MS = 200;
		//private TouchAction mLastAction;
		
		private final void startTouch(TEInputTouch touch) {
			mStartTime = SystemClock.uptimeMillis();
			final long elapsedTime = mStartTime - mLastUpTime;
			if (elapsedTime > TAP_UP_THRESHOLD_MS) {
				Log.v("TouchDrag.startTouch", "failed tap");
				mTapCount = 0;
			}
		}
		
		private final void endTouch(TEInputTouch touch) {
			mLastUpTime = SystemClock.uptimeMillis();
			final long elapsedTime = mLastUpTime - mStartTime;
			Log.v("TouchDrag.endTouch", "ended");
			if (elapsedTime < TAP_DOWN_THRESHOLD_MS) {
				++mTapCount;
				switch(mTapCount) {
                    case 1:
                        //mLastAction = TouchAction.TAP;
                        break;
                    case 2:
                        //mLastAction = TouchAction.DOUBLE_TAP;
                        parent.invokeEvent(Event.EVENT_MOVE_TO_FOUNDATION);
                        break;
				}
			} else {
				mTapCount = 0;
				//mLastAction = TouchAction.NONE;
			}
		}
		
		//private final long splitTime() {
		//	return SystemClock.uptimeMillis() - mStartTime;
		//}
	}
	
	
}
*/