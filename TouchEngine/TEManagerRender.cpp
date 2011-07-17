//
//  TEManagerRender.cpp
//  TouchEngine
//
//  Created by geminileft on 7/16/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TEManagerRender.h"

/*
private static TEManagerRender mSharedInstance = null;
	
	private TEComponent.EventListener mTouchStartedListener = new TEComponent.EventListener() {
		
		public void invoke() {
		}
	};
	
	public static TEManagerRender sharedManager() {
		if (mSharedInstance == null) {
			mSharedInstance = new TEManagerRender();
		}
		return mSharedInstance;
	}
    
	public TEManagerRender() {
		super();
	}
	
	public void update() {
		TEComponentContainer components = getComponents();
		final int size = components.size();
		for(int i = 0; i < size; ++i) {
            TEComponentRender component = (TEComponentRender)components.get(i);
            component.update();
            component.draw();
        }
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