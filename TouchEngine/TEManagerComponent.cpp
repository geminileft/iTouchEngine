
#include "TEManagerComponent.h"

TEComponentContainer TEManagerComponent::getComponents() const {
    return mComponents;
}

void TEManagerComponent::addComponent(TEComponent* component) {
    addComponent(component, -1);
}

void TEManagerComponent::addComponent(TEComponent* component, int index) {
    if (index == -1) {
        mComponents.push_back(component);
    } else {
        mComponents.push_front(component);
        //mComponents.add(index, component);
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
	
	
	public abstract void moveComponentToTop(TEComponent component);
}
*/