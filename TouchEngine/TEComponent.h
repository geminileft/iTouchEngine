class TEManagerComponent;

#ifndef TECOMPONENT
#define TECOMPONENT

#include "TEManagerComponent.h"

class TEComponent {
private:
    TEManagerComponent* mManager;
    
public:
    virtual void update() = 0;

    void setManager(TEManagerComponent* manager);
};

#endif