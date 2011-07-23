#ifndef TEMANAGERINPUT
#define TEMANAGERINPUT

class TEInputTouch;

#include "TEManagerComponent.h"

class TEManagerInput : TEManagerComponent {
public:
    static TEManagerInput* sharedManager();
    virtual void update();
    void beginTouch(TEInputTouch* touch);
};

#endif