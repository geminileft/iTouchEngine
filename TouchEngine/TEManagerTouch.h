#ifndef TEMANAGERTOUCH
#define TEMANAGERTOUCH

#include "TEManagerComponent.h"

class TEManagerTouch : public TEManagerComponent {
public:
    void update();
	static TEManagerTouch* sharedManager();
};

#endif