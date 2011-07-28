#include "TEGameObject.h"
#include "TEComponent.h"

void TEGameObject::update() {}

void TEGameObject::addComponent(TEComponent* component) {
    TEManagerComponent::addComponent(component);
    /*
    HashMap<TEComponent.Event, TEComponent.EventListener> eventSubscriptions = component.getEventSubscriptions();
    if (!eventSubscriptions.isEmpty()) {
        Set<TEComponent.Event> keys = eventSubscriptions.keySet();
        Iterator<TEComponent.Event> iterator = keys.iterator();
        while (iterator.hasNext()) {
            TEComponent.Event event = iterator.next();
            addEventSubscription(event, eventSubscriptions.get(event));
        }
    }
    */
    component->setParent(this);		
}

void TEGameObject::moveComponentToTop(TEComponent* component) {}

/*
private HashMap<TEComponent.Event, Vector<TEComponent.EventListener>> mEventSubscribers = new HashMap<TEComponent.Event, Vector<TEComponent.EventListener>>(); 
		
	public TEGameObject() {
		super();
	}
		
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
	
	public final void addEventSubscription(TEComponent.Event event, TEComponent.EventListener eventListener) {
		Vector<TEComponent.EventListener> subscribers = mEventSubscribers.get(event);
		if (subscribers == null) {
			subscribers = new Vector<TEComponent.EventListener>();
		}
		subscribers.add(eventListener);
		mEventSubscribers.put(event, subscribers);
	}
    
}
*/