//
//  TEManagerRender.cpp
//  TouchEngine
//
//  Created by geminileft on 7/16/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TEComponentRender.h"
#include "TEManagerRender.h"
#import <QuartzCore/QuartzCore.h>
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

static TEManagerRender* mSharedInstance = NULL;

void TEManagerRender::update() {
    TEComponentContainer components = getComponents();
    TEComponentContainer::iterator iterator;
    glClear(GL_COLOR_BUFFER_BIT);
    for (iterator = components.begin(); iterator != components.end();iterator++) {
        TEComponentRender* component = (TEComponentRender*)(*iterator);
        component->update();
        component->draw();
    }
}

void TEManagerRender::moveComponentToTop(TEComponent* component) {
	TEComponentContainer components = getComponents();
	components.remove(component);
	addComponent(component, Bottom);			
}

TEManagerRender* TEManagerRender::sharedManager() {
    if (mSharedInstance == NULL) {
        mSharedInstance = new TEManagerRender();
    }
    return mSharedInstance;
}
