#ifndef TEMANAGERCOMPONENT
#define TEMANAGERCOMPONENT

#include "TEManager.h"
#include "TETypes.h"

class TEComponent;

class TEManagerComponent : public TEManager {
private:
	TEComponentContainer mComponents;


public:
    TEComponentContainer getComponents() const;
	void addComponent(TEComponent* component);
    void addComponent(TEComponent* component, int index);
	virtual void moveComponentToTop(TEComponent* component) = 0;
	virtual void update();
};

#endif