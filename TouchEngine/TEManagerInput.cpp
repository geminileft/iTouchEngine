#include "TEManagerInput.h"
#include "TEInputTouch.h"

static TEManagerInput* mSharedInstance = NULL;

TEManagerInput* TEManagerInput::sharedManager() {
    if (mSharedInstance == NULL) {
        mSharedInstance = new TEManagerInput();
    }
    return mSharedInstance;
}

void TEManagerInput::beginTouch(TEInputTouch* touch) {
    mTouches[touch->getPointerId()] = touch;
}

void TEManagerInput::moveTouch(TEInputTouch* touch) {
    std::map<unsigned int, TEInputTouch*>::iterator iterator = mTouches.find(touch->getPointerId());
    if (iterator != mTouches.end()) {
        iterator->second->setEndPoint(touch->getEndPoint());
    }
}

void TEManagerInput::endTouch(TEInputTouch* touch) {
    std::map<unsigned int, TEInputTouch*>::iterator iterator = mTouches.find(touch->getPointerId());
    if (iterator != mTouches.end()) {
        iterator->second->endTouch(touch->getEndPoint());
    }
}

std::map<unsigned int, TEInputTouch*> TEManagerInput::getInputState() {
    std::map<unsigned int, TEInputTouch*> touchState;
    TEInputTouch* addTouch;
    std::map<unsigned int, TEInputTouch*>::iterator iterator;
    for(iterator = mTouches.begin();iterator != mTouches.end();++iterator) {
        addTouch = (*iterator).second->copy();
        touchState[addTouch->getPointerId()] = addTouch;
        if (addTouch->ended()) {
            mTouches.erase(iterator);
        } else {
            (*iterator).second->reset();
        }
    }
    return touchState;
}