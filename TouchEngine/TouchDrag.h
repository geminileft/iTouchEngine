#ifndef TOUCHDRAG
#define TOUCHDRAG

class TEInputTouch;

#include "TEComponentTouch.h"

class TouchDrag : public TEComponentTouch {
private:
	TEInputTouch* mTouch;
	TEPoint mTouchOffset;
	bool mTouchValid;

public:
    TouchDrag();
    virtual void update();
    virtual bool addTouch(TEInputTouch* touch);
	virtual bool updateTouch(TEInputTouch* touch);
};

#endif