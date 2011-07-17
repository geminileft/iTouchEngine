#ifndef TEMANAGERCOMPONENT
#define TEMANAGERCOMPONENT

#include "TEManager.h"
#include "TEComponentContainer.h"

class TEManagerComponent : public TEManager {
private:
	TEComponentContainer mComponents;

public:
    TEComponentContainer getComponents() const;

};
    
#endif