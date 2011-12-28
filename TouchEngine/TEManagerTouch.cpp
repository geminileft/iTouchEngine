#include "TEManagerTouch.h"
#include "TEComponent.h"
#include "TEComponentTouch.h"
#include "TEManagerInput.h"
#include "TEInputTouch.h"

static TEManagerTouch* mSharedInstance = NULL;

void TEManagerTouch::update() {
    TEComponentContainer components = getComponents();
    TEComponentContainer::iterator componentIterator;
    TEComponentTouch* component;
    TEManagerInput* inputManager = TEManagerInput::sharedManager();
    std::map<unsigned int, TEInputTouch*> inputState = inputManager->getInputState();
    std::map<unsigned int, TEInputTouch*>::iterator iterator;
    std::map<unsigned int, TEComponentTouch*>::iterator eIterator;
    TEInputTouch* touch;
    for(iterator = inputState.begin();iterator != inputState.end();++iterator) {
        touch = (*iterator).second;
        if (touch->began()) {
            for (componentIterator = components.begin(); componentIterator != components.end();++componentIterator++) {
                component = (TEComponentTouch*)(*componentIterator);
                if (component->containsPoint(touch->getStartPoint())) {
                    if (component->addTouch(touch) && !touch->ended()) {
                        mTouchComponents[touch->getPointerId()]= component;
                    }
                    break;
                }
            }
        } else {
            eIterator = mTouchComponents.find(touch->getPointerId());
			if (eIterator != mTouchComponents.end()) {
                component = (*eIterator).second;
                component->updateTouch(touch);
                mTouchComponents[touch->getPointerId()] = component;
            }
        }
    }
    for (componentIterator = components.begin(); componentIterator != components.end();++componentIterator) {
        component = (TEComponentTouch*)(*componentIterator);
        component->update();
    }
}

TEManagerTouch* TEManagerTouch::sharedManager() {
    if (mSharedInstance == NULL) {
        mSharedInstance = new TEManagerTouch();
    }
    return mSharedInstance;
}

void TEManagerTouch::moveComponentToTop(TEComponent* component) {
	TEComponentContainer components = getComponents();
	components.remove(component);
	addComponent(component, Top);	
}
