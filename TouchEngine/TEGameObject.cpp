#include "TEGameObject.h"
#include "TEEventListenerBase.h"
#include "TEComponent.h"

void TEGameObject::update() {}

void TEGameObject::addComponent(TEComponent* component) {
    TEManagerComponent::addComponent(component, Top);
	std::map<TEComponentEvent, TEEventListenerBase*> eventSubscriptions = component->getEventSubscriptions();
    if (!eventSubscriptions.empty()) {
		std::map<TEComponentEvent, TEEventListenerBase*>::iterator iterator;
		for (iterator = eventSubscriptions.begin();iterator != eventSubscriptions.end();++iterator) {
            TEComponentEvent event = (*iterator).first;
            addEventSubscription(event, (*iterator).second);
        }
    }
    component->setParent(this);		
}

void TEGameObject::moveComponentToTop(TEComponent* component) {}

void TEGameObject::invokeEvent(TEComponentEvent event) {
	std::map<TEComponentEvent, std::vector<TEEventListenerBase*> >::iterator iterator; 
	iterator = mEventSubscribers.find(event);
	if (iterator != mEventSubscribers.end()) {
		std::vector<TEEventListenerBase*> subscribers = (*iterator).second;
		if (!subscribers.empty()) {
			std::vector<TEEventListenerBase*>::iterator subscriberIterator;
			for (subscriberIterator = subscribers.begin();subscriberIterator != subscribers.end();++subscriberIterator) {
				(*subscriberIterator)->invoke();
			}

		}
	}
}

void TEGameObject::addEventSubscription(TEComponentEvent event, TEEventListenerBase* eventListener) {
	std::map<TEComponentEvent, std::vector<TEEventListenerBase*> >::iterator iterator;
	iterator = mEventSubscribers.find(event);
	std::vector<TEEventListenerBase*> subscribers;
	if (iterator != mEventSubscribers.end()) {
		subscribers = (*iterator).second;
	}
	subscribers.push_back(eventListener);
	mEventSubscribers[event] = subscribers;
}