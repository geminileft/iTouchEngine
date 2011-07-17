#ifndef TECOMPONENT
#define TECOMPONENT

#include "TEGameObject.h"

class TEGameObject;

class TEComponent {
public:
    TEGameObject* mParent;
    virtual void update() = 0;

};

#endif