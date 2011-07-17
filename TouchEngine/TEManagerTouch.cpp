

#include "TEManagerTouch.h"

static TEManagerTouch* mSharedInstance = NULL;

void TEManagerTouch::update() {
    TEComponentContainer components = getComponents();
    TEComponentContainer::iterator iterator;
    
    for (iterator = components.begin(); iterator != components.end();iterator++) {
        TEComponent* component = (*iterator);
        component->update();
        //component->draw();
    }
}

TEManagerTouch* TEManagerTouch::sharedManager() {
    if (mSharedInstance == NULL) {
        mSharedInstance = new TEManagerTouch();
    }
    return mSharedInstance;
}
/*
 public class TEManagerTouch extends TEManagerComponent {
	private static TEManagerTouch mSharedInstance = null;
	private HashMap<Integer, TEComponentTouch> mTouchComponents;
	
	public TEManagerTouch() {
		mTouchComponents = new HashMap<Integer, TEComponentTouch>();
	}
	
	public static TEManagerTouch sharedManager() {
		if (mSharedInstance == null) {
			mSharedInstance = new TEManagerTouch();
		}
		return mSharedInstance;
	}
    
	@Override
	public void update() {
		TEComponentContainer components = getComponents();
		TEComponentTouch component;
		TEManagerInput inputManager = TEManagerInput.sharedManager();
		HashMap<Integer, TEInputTouch> inputState = inputManager.getInputState();
		Collection<TEInputTouch> collection = inputState.values();
		Iterator<TEInputTouch> iterator = collection.iterator();
		TEInputTouch touch;
		while (iterator.hasNext()) {
			touch = iterator.next();
			if (touch.began()) {
				final int size = components.size();
                for(int i = 0;i < size;++i) {
                    component = (TEComponentTouch)components.get(i);
                    if (component.containsPoint(touch.getStartPoint())) {
						if (component.addTouch(touch) && !touch.ended()) {
							mTouchComponents.put(touch.getPointerId(), component);
						}
						break;
                    }
			    }
			} else {
				if (mTouchComponents.containsKey(touch.getPointerId())) {
					component = mTouchComponents.get(touch.getPointerId());
					component.updateTouch(touch);
					mTouchComponents.put(touch.getPointerId(), component);
				}
			}
		}
		final int size = components.size();
	    for(int i = 0;i < size;++i) {
	    	component = (TEComponentTouch)components.get(i);
	    	component.update();
	    }
	}
    
	public final void moveComponentToTop(TEComponent component) {
		TEComponentContainer components = getComponents();
		if (components.remove(component)) {
			addComponent(component, 0);	
		} else {
			Log.v("TEManagerComponent.moveComponentToTop", "did not find component");
		}
	}
    
}
*/