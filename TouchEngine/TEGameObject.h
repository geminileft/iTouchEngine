#ifndef TEGAMEOBJECT
#define TEGAMEOBJECT

#include "TEManagerComponent.h"
#include "TETypes.h"

class TEGameObject : public TEManagerComponent {

public:
	TESize size;
	TEPoint position;
    virtual void update();
    void addComponent(TEComponent* component);
	virtual void moveComponentToTop(TEComponent* component);
};

#endif