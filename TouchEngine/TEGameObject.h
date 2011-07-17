#ifndef TEGAMEOBJECT
#define TEGAMEOBJECT

#include "TEManagerComponent.h"
#include "TETypes.h"

class TEGameObject : public TEManagerComponent {

public:
	TESize size;
	TEPoint position;
    virtual void update();
};

#endif