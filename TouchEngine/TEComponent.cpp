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
	public interface EventListener {
		public abstract void invoke();
	}	
	public static enum Event {
		EVENT_TOUCH_STARTED
		, EVENT_TOUCH_REJECT
		, EVENT_TOUCH_ACCEPT
		, EVENT_TOUCH_ENDED
		, EVENT_MOVE_TO_TOP
		, EVENT_ACCEPT_MOVE
		, EVENT_REJECT_MOVE
		, EVENT_MOVE_TO_FOUNDATION
	}
	
	
	private HashMap<TEComponent.Event, EventListener> mEventSubscriptions = new HashMap<TEComponent.Event, EventListener>();
    	
	public final void addEventSubscription(TEComponent.Event event, EventListener listener) {
		mEventSubscriptions.put(event, listener);
	}
	
	public final HashMap<TEComponent.Event, EventListener> getEventSubscriptions() {
		return mEventSubscriptions;
	}
}
 */
