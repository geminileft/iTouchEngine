#ifndef TEMANAGERCOMPONENT
#define TEMANAGERCOMPONENT

#include "TEManager.h"
#include "TEComponentContainer.h"

class TEManagerComponent : public TEManager {
private:
	TEComponentContainer mComponents;

public:
    TEComponentContainer getComponents() const;
    void addComponent(TEComponent* component, int index);
	void addComponent(TEComponent* component);

};
    
#endif