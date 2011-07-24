#ifndef TEMANAGERINPUT
#define TEMANAGERINPUT

class TEInputTouch;

#include "TEManagerComponent.h"
#include <map>
class TEManagerInput {
private:
    std::map<int, TEInputTouch*> mTouches;

public:
    static TEManagerInput* sharedManager();
    void beginTouch(TEInputTouch* touch);
    void moveTouch(TEInputTouch* touch);
    void endTouch(TEInputTouch* touch);
};

#endif