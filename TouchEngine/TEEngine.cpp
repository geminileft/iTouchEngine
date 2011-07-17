#include "TEEngine.h"
#include "TEManagerRender.h"
#include "TEManagerTouch.h"
#include "TEComponentRender.h"
#include "TEComponentTouch.h"
#include "TEGameObject.h"
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
/*
	private Context mContext;
	private Vector<TEGameObject> mGameObjects;
	private int mHeight;
	private int mWidth;
*/
    
TEEngine::TEEngine() {
        /*
        TEManagerStack stackManager = TEManagerStack.sharedManager();
        TEManagerSound soundManager = TEManagerSound.sharedManager();
        */
    TEManagerTouch* touchManager = TEManagerTouch::sharedManager();
    TEManagerRender* renderManager = TEManagerRender::sharedManager();
        /*
        mManagers.add(stackManager);
        mManagers.add(soundManager);
        */
    mManagers.push_back(touchManager);
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
    /*
    TEManagerSound soundManager = TEManagerSound.sharedManager();
    TEManagerStack stackManager = TEManagerStack.sharedManager();
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
/*
        } else if (component instanceof TEComponentSound) {
            soundManager.addComponent(component);
        } else if (component instanceof TEComponentStack) {
            stackManager.addComponent(component);
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
    glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glOrthof(0.0f, width, 0.0f, height, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/*	
	Context getContext() {
		return mContext;
	}
    
    public boolean onTouchEvent(MotionEvent event) {
    	TEManagerInput inputManager = TEManagerInput.sharedManager();
    	int pointerId;
    	float x;
    	float y;
    	final int actionId = event.getAction();
    	TEInputTouch touch;
    	
    	final int pointerCount = event.getPointerCount();
    	for (int i = 0;i < pointerCount; ++i) {
    		pointerId = event.getPointerId(i);
    		x = event.getX(pointerId);
    		y = mHeight - event.getY(pointerId);    		
        	switch (actionId) {
                case MotionEvent.ACTION_DOWN:
                    touch = new TEInputTouch(pointerId, x, y);
                    inputManager.beginTouch(touch);
                    break;
                case MotionEvent.ACTION_MOVE:
                    touch = new TEInputTouch(pointerId, x, y);
                    inputManager.moveTouch(touch);
                    break;
                case MotionEvent.ACTION_UP:
                    touch = new TEInputTouch(pointerId, x, y);
                    inputManager.endTouch(touch);
                    break;
                default:
                    Log.v("info", "Couldn't identify " + String.valueOf(actionId));
                    break;
        	}
    	}
    	return false;
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