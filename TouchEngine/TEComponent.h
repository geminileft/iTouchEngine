#ifndef TECOMPONENT
#define TECOMPONENT

#include "TEGameObject.h"

class TEComponent {
public:
    TEGameObject* mParent;
    virtual void update() = 0;
	void setParent(TEGameObject* parentGameObject);

};

#endif