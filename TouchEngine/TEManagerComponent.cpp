
#include "TEManagerComponent.h"

TEComponentContainer TEManagerComponent::getComponents() const {
    return mComponents;
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
	
	public void addComponent(TEComponent component) {
		addComponent(component, -1);
	}
	
	public void addComponent(TEComponent component, int index) {
		if (index == -1) {
			mComponents.add(component);
		} else {
			mComponents.add(index, component);
		}
		component.setManager(this);
	}
	
	public abstract void moveComponentToTop(TEComponent component);
}
*/