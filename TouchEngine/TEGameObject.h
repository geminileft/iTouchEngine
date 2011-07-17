#ifndef TEGAMEOBJECT
#define TEGAMEOBJECT

#include "TEManagerComponent.h"

class TEGameObject : public TEManagerComponent {

public:
    virtual void update();
};

#endif