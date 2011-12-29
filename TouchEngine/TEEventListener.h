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
