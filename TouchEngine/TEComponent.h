#ifndef TECOMPONENT
#define TECOMPONENT

#include "TEGameObject.h"
#include <map>

class TEComponent;

class TEEventListener;

enum TEComponentEvent {
	EVENT_TOUCH_STARTED
	, EVENT_TOUCH_REJECT
	, EVENT_TOUCH_ACCEPT
	, EVENT_TOUCH_ENDED
	, EVENT_MOVE_TO_TOP
	, EVENT_ACCEPT_MOVE
	, EVENT_REJECT_MOVE
	, EVENT_MOVE_TO_FOUNDATION
};

typedef TEComponentEvent TEComponentEvent;

class TEComponent {
private:
	TEManagerComponent* mManager;
	//std::map<TEComponentEvent, EventListener*> mEventSubscriptions;

public:
    TEGameObject* mParent;
    virtual void update() = 0;
	void setParent(TEGameObject* parentGameObject);
	void setManager(TEManagerComponent* manager);
	TEManagerComponent* getManager();
	//void addEventSubscription(TEComponentEvent event, EventListener* listener);
};

#endif