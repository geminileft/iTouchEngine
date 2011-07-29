#include "TEGameObject.h"

void TEGameObject::update() {}

void TEGameObject::addComponent(TEComponent* component) {
    TEManagerComponent::addComponent(component);
	std::map<TEComponentEvent, TEEventListenerBase*> eventSubscriptions = component->getEventSubscriptions();
    if (eventSubscriptions.empty()) {
		std::map<TEComponentEvent, TEEventListenerBase*>::iterator iterator;
		for (iterator = eventSubscriptions.begin();iterator != eventSubscriptions.end();++iterator) {
            TEComponentEvent event = (*iterator).first;
            addEventSubscription(event, (*iterator).second);
        }
    }
    component->setParent(this);		
}

void TEGameObject::moveComponentToTop(TEComponent* component) {}

/*
	public void invokeEvent(TEComponent.Event event) {
		Vector<TEComponent.EventListener> subscribers = mEventSubscribers.get(event);
		if (subscribers != null) {
			Iterator<TEComponent.EventListener> iterator = subscribers.iterator();
			while (iterator.hasNext()) {
				TEComponent.EventListener eventListener = iterator.next();
				eventListener.invoke();
			}
		}
	}
*/

void TEGameObject::addEventSubscription(TEComponentEvent event, TEEventListenerBase* eventListener) {
	std::map<TEComponentEvent, std::vector<TEEventListenerBase*> >::iterator iterator;
	iterator = mEventSubscribers.find(event);
	std::vector<TEEventListenerBase*> subscribers = (*iterator).second;
	subscribers.push_back(eventListener);
	mEventSubscribers[event] = subscribers;
}