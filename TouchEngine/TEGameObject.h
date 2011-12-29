#ifndef TEGAMEOBJECT
#define TEGAMEOBJECT

#include "TEManagerComponent.h"
#include "TETypes.h"
#include <map>
#include <vector>

class TEEventListenerBase;

class TEGameObject : public TEManagerComponent {
private:
	std::map<TEComponentEvent, std::vector<TEEventListenerBase*> > mEventSubscribers; 

public:
	TESize size;
	TEPoint position;
	
    virtual void update();
    void addComponent(TEComponent* component);
	virtual void moveComponentToTop(TEComponent* component);
	void addEventSubscription(TEComponentEvent event, TEEventListenerBase* eventListener);
	void invokeEvent(TEComponentEvent event);
};

#endif