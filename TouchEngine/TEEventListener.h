//
//  TEEventListener.h
//  TouchEngine
//
//  Created by geminileft on 7/28/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef TEEVENTLISTENER
#define TEEVENTLISTENER

#include "TEEventListenerBase.h"

template <class T>
class TEEventListener : public TEEventListenerBase {
private:
	T* mObject;
	void (T::*mInvoke)();
	
public:
	TEEventListener(T* object, void (T::*invoke)()) {
		mObject = object;
		mInvoke = invoke;
	}
	
	virtual void invoke() {
		(*mObject.*mInvoke)();
	}
};
#endif
