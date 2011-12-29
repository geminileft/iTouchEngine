#include "TEManagerComponent.h"
#include "TEComponent.h"

TEComponentContainer TEManagerComponent::getComponents() const {
    return mComponents;
}

void TEManagerComponent::addComponent(TEComponent* component, ComponentLocation location) {
    if (location == Bottom) {
        mComponents.push_back(component);
    } else {
        mComponents.push_front(component);
    }
	component->setManager(this);
}

void TEManagerComponent::update() {
	TEComponentContainer components = getComponents();
	TEComponentContainer::iterator iterator;
	for(iterator = components.begin();iterator != components.end();++iterator) {
		(*iterator)->update();
	}
}
