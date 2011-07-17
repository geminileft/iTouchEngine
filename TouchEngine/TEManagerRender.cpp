//
//  TEManagerRender.cpp
//  TouchEngine
//
//  Created by geminileft on 7/16/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TEComponentRender.h"
#include "TEManagerRender.h"

static TEManagerRender* mSharedInstance = NULL;

void TEManagerRender::update() {
    TEComponentContainer components = getComponents();
    TEComponentContainer::iterator iterator;
    
    for (iterator = components.begin(); iterator != components.end();iterator++) {
        TEComponentRender* component = (TEComponentRender*)(*iterator);
        component->update();
        component->draw();
    }
}

TEManagerRender* TEManagerRender::sharedManager() {
    if (mSharedInstance == NULL) {
        mSharedInstance = new TEManagerRender();
    }
    return mSharedInstance;
}
/*
	
	private TEComponent.EventListener mTouchStartedListener = new TEComponent.EventListener() {
		
		public void invoke() {
		}
	};
	
    
	public TEManagerRender() {
		super();
	}
	
	
	public TEComponent.EventListener getTouchStartedListener() {
		return mTouchStartedListener;
	}
    
	public final void moveComponentToTop(TEComponent component) {
		TEComponentContainer components = getComponents();
		if (components.remove(component)) {
			int size = components.size();
			addComponent(component, size);			
		} else {
			Log.v("TEManagerComponent.moveComponentToTop", "did not find component");
		}
	}
}
*/