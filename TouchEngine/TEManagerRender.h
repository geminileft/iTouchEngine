#ifndef TEMANAGERRENDER
#define TEMANAGERRENDER

#include "TEManagerComponent.h"

class TEManagerRender : public TEManagerComponent {

public:
    void update();
	static TEManagerRender* sharedManager();
	virtual void moveComponentToTop(TEComponent* component);
};
#endif