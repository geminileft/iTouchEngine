#ifndef TEMANAGERTOUCH
#define TEMANAGERTOUCH

class TEComponentTouch;

#include "TEManagerComponent.h"
#include <map>

class TEManagerTouch : public TEManagerComponent {
private:
    std::map<unsigned int, TEComponentTouch*> mTouchComponents;

public:
    void update();
	static TEManagerTouch* sharedManager();
};

#endif