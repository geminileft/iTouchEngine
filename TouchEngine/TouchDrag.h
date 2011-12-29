#ifndef TOUCHDRAG
#define TOUCHDRAG

#define TAP_DOWN_THRESHOLD_MS 130
#define TAP_UP_THRESHOLD_MS 200

#include "TEComponentTouch.h"

class TEInputTouch;

enum TouchAction {
	NONE
	, TAP
	, DOUBLE_TAP
};

typedef TouchAction TouchAction;



class TouchDrag : public TEComponentTouch {
private:
	TEInputTouch* mTouch;
	TEPoint mTouchOffset;
	bool mTouchValid;
	long mStartTime;
	int mTapCount;
	long mLastUpTime;

public:
    TouchDrag();
    virtual void update();
    virtual bool addTouch(TEInputTouch* touch);
	virtual bool updateTouch(TEInputTouch* touch);
	void touchAcceptListener();
	void touchRejectListener();
};

#endif