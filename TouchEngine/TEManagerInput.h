#ifndef TEMANAGERINPUT
#define TEMANAGERINPUT

#include <map>

class TEInputTouch;

class TEManagerInput {
private:
    std::map<unsigned int, TEInputTouch*> mTouches;

public:
    static TEManagerInput* sharedManager();
    void beginTouch(TEInputTouch* touch);
    void moveTouch(TEInputTouch* touch);
    void endTouch(TEInputTouch* touch);
    std::map<unsigned int, TEInputTouch*> getInputState();
};

#endif