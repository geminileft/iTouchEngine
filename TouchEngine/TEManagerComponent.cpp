
#include "TEManagerComponent.h"
#include "TEComponent.h"

TEComponentContainer TEManagerComponent::getComponents() const {
    return mComponents;
}

void TEManagerComponent::addComponent(TEComponent* component) {
    addComponent(component, LAST_INDEX);
}

void TEManagerComponent::addComponent(TEComponent* component, int index) {
    if (index == LAST_INDEX) {
        mComponents.push_back(component);
    } else {
        mComponents.push_front(component);
    }
	component->setManager(this);
}

/*
public void update() {
		TEComponentContainer components = getComponents();
		final int size = components.size();
		for(int i = 0; i < size; ++i) {
			TEComponent component = components.get(i);
	    	component.update();
	    }
	}
	
	
}
*/