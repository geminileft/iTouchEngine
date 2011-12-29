#ifndef TECOMPONENT
#define TECOMPONENT

#include "TETypes.h"
#include <map>

#define LAST_INDEX -1

class TEComponent;
class TEManagerComponent;
class TEGameObject;
class TEEventListenerBase;

class TEComponent {
private:
	TEManagerComponent* mManager;
	std::map<TEComponentEvent, TEEventListenerBase*> mEventSubscriptions;

public:
    TEGameObject* mParent;
    virtual void update() = 0;
	void setParent(TEGameObject* parentGameObject);
	void setManager(TEManagerComponent* manager);
	TEManagerComponent* getManager();
	void addEventSubscription(TEComponentEvent event, TEEventListenerBase* listener);
	const std::map<TEComponentEvent, TEEventListenerBase*> getEventSubscriptions() const;
};

#endif