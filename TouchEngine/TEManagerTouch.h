#ifndef TEMANAGERTOUCH
#define TEMANAGERTOUCH

#include "TEManagerComponent.h"
#include <map>

class TEComponentTouch;

class TEManagerTouch : public TEManagerComponent {
private:
    std::map<unsigned int, TEComponentTouch*> mTouchComponents;

public:
    void update();
	static TEManagerTouch* sharedManager();
	virtual void moveComponentToTop(TEComponent* component);
};

#endif