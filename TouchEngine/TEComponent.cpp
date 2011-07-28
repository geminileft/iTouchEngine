#include "TEComponent.h"

void TEComponent::setParent(TEGameObject* parentGameObject) {
    mParent = parentGameObject;
}

void TEComponent::setManager(TEManagerComponent* manager) {
	mManager = manager;
}

TEManagerComponent* TEComponent::getManager() {
	return mManager;
}

/*
void TEComponent::addEventSubscription(TEComponentEvent event, EventListener* listener) {
	mEventSubscriptions[event] = listener;
}
*/

/*
	public final HashMap<TEComponent.Event, EventListener> getEventSubscriptions() {
		return mEventSubscriptions;
	}
}
 */
