#ifndef TEMANAGERCOMPONENT
#define TEMANAGERCOMPONENT

#include "TEManager.h"
#include "TETypes.h"

enum ComponentLocation {
	Top
	, Bottom
};

typedef ComponentLocation ComponentLocation;

class TEComponent;

class TEManagerComponent : public TEManager {
private:
	TEComponentContainer mComponents;

public:
    TEComponentContainer getComponents() const;
    void addComponent(TEComponent* component, ComponentLocation location);
	virtual void moveComponentToTop(TEComponent* component) = 0;
	virtual void update();
};

#endif