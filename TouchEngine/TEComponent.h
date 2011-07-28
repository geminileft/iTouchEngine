#ifndef TECOMPONENT
#define TECOMPONENT

#include "TEGameObject.h"

class TEComponent {
private:
	TEManagerComponent* mManager;

public:
    TEGameObject* mParent;
    virtual void update() = 0;
	void setParent(TEGameObject* parentGameObject);
	void setManager(TEManagerComponent* manager);
	TEManagerComponent* getManager();

};

#endif