#include "TEEngine.h"
#include "TEGameObject.h"
#include "TEManagerRender.h"
#include "TEManagerTouch.h"
#include "TEManagerStack.h"
#include "TEManagerSound.h"
#include "TEComponentRender.h"
#include "TEComponentTouch.h"
#include "TEComponentStack.h"
#include "TEComponentSound.h"
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
    
TEEngine::TEEngine(int width, int height) {
	mWidth = width;
	mHeight = height;
    TEManagerTouch* touchManager = TEManagerTouch::sharedManager();
    TEManagerStack* stackManager = TEManagerStack::sharedManager();
    TEManagerSound* soundManager = TEManagerSound::sharedManager();
    TEManagerRender* renderManager = TEManagerRender::sharedManager();
    mManagers.push_back(touchManager);
    mManagers.push_back(stackManager);
    mManagers.push_back(soundManager);
    mManagers.push_back(renderManager);
	}

void TEEngine::run() {
    int managerCount = mManagers.size();
    for (int count = 0;count < managerCount; ++count) {
        mManagers[count]->update();
    }
}

void TEEngine::addGameObject(TEGameObject* gameObject) {
    TEManagerRender* renderManager = TEManagerRender::sharedManager();
    TEManagerTouch* touchManager = TEManagerTouch::sharedManager();
    TEManagerStack* stackManager = TEManagerStack::sharedManager();
    TEManagerSound* soundManager = TEManagerSound::sharedManager();
    TEComponentContainer components = gameObject->getComponents();
    TEComponentContainer::iterator iterator;
    TEComponent* component;
    for(iterator = components.begin();iterator != components.end();++iterator) {
        component = *iterator;
        if (dynamic_cast<TEComponentRender*>(component)) {
            renderManager->addComponent(component, Bottom);
        } else if (dynamic_cast<TEComponentTouch*>(component)) {
            touchManager->addComponent(component, Top);
        } else if (dynamic_cast<TEComponentStack*>(component)) {
            stackManager->addComponent(component, Top);
        } else if (dynamic_cast<TEComponentSound*>(component)) {
            soundManager->addComponent(component, Top);
        }
    }
    mGameObjects.push_back(gameObject);
}

TESize TEEngine::getScreenSize() const {
	TESize size;
	size.width = mWidth;
	size.height = mHeight;
	return size;
}
