#include "TEEngine.h"
#include "TEManagerRender.h"
#include "TEManagerTouch.h"
#include "TEManagerStack.h"
#include "TEComponentRender.h"
#include "TEComponentTouch.h"
#include "TEComponentStack.h"
#include "TEGameObject.h"
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
    
TEEngine::TEEngine(int width, int height) {
	mWidth = width;
	mHeight = height;
    TEManagerTouch* touchManager = TEManagerTouch::sharedManager();
    TEManagerStack* stackManager = TEManagerStack::sharedManager();
    //TEManagerSound soundManager = TEManagerSound.sharedManager();
    TEManagerRender* renderManager = TEManagerRender::sharedManager();
    mManagers.push_back(touchManager);
    mManagers.push_back(stackManager);
    //mManagers.add(soundManager);
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
    /*
    TEManagerSound soundManager = TEManagerSound.sharedManager();
    */
    TEComponentContainer components = gameObject->getComponents();
    TEComponentContainer::iterator iterator;
    TEComponent* component;
    for(iterator = components.begin();iterator != components.end();++iterator) {
        component = *iterator;
        if (dynamic_cast<TEComponentRender*>(component)) {
            renderManager->addComponent(component);
        } else if (dynamic_cast<TEComponentTouch*>(component)) {
            touchManager->addComponent(component);
        } else if (dynamic_cast<TEComponentStack*>(component)) {
            stackManager->addComponent(component);
/*
        } else if (component instanceof TEComponentSound) {
            soundManager.addComponent(component);
*/
        }
    }
    mGameObjects.push_back(gameObject);
}

void TEEngine::initGraphics(int width, int height) {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //always drawing textures...enable once
    //glEnable(GL_TEXTURE_2D);
    //required for vertex/textures
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glClearColor(0.4f, 0.7f, 0.12f, 1.0f);
	graphicsChange(width, height);

}

void TEEngine::graphicsChange(int width, int height) {
/*
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glOrthof(0.0f, width, 0.0f, height, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
*/
	bool useOrtho = true;
	const int zDepth = height / 2;
	const float ratio = (float)width / height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	if (useOrtho) {
		glOrthof(0.0f, width, 0.0f, height, 0.0f, 1.0f);
	} else {
		glFrustumf(-ratio, ratio, -1, 1, 1, zDepth);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (!useOrtho) {
		glTranslatef(-width / 2, -height / 2, -zDepth);				
	}
}

/*	
	Context getContext() {
		return mContext;
	}
    
    public void setScreenSize(int width, int height) {
    	mHeight = height;
    	mWidth = width;
		TEManagerGraphics.setScreenSize(width, height);
    }
    
    public Size getScreenSize() {
    	return new Size(mWidth, mHeight);
    }
*/