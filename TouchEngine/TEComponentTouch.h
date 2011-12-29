#ifndef TECOMPONENTTOUCH
#define TECOMPONENTTOUCH

#include "TEComponent.h"
#include "TETypes.h"

class TEInputTouch;

class TEComponentTouch : public TEComponent {

public:
    virtual bool addTouch(TEInputTouch* touch) = 0;
	virtual bool updateTouch(TEInputTouch* touch) = 0;
	bool containsPoint(TEPoint point);
};

#endif