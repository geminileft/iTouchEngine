#include "TEComponent.h"
#include "TEGameObject.h"
#include "TEEventListener.h"

void TEComponent::setParent(TEGameObject* parentGameObject) {
    mParent = parentGameObject;
}

void TEComponent::setManager(TEManagerComponent* manager) {
	mManager = manager;
}

TEManagerComponent* TEComponent::getManager() {
	return mManager;
}

void TEComponent::addEventSubscription(TEComponentEvent event, TEEventListenerBase* listener) {
	mEventSubscriptions[event] = listener;
}

const std::map<TEComponentEvent, TEEventListenerBase*> TEComponent::getEventSubscriptions() const {
	return mEventSubscriptions;
}
