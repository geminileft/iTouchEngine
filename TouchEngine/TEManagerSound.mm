#include "TEManagerSound.h"
#include <OpenAL/al.h>

static TEManagerSound* mSharedInstance = NULL;

TEManagerSound::TEManagerSound() {
	mDevice = alcOpenDevice(NULL); // select the "preferred device"
	if (mDevice) {
		mContext = alcCreateContext(mDevice, NULL);
		alcMakeContextCurrent(mContext);
	}
}

TEManagerSound* TEManagerSound::sharedManager() {
	if (mSharedInstance == NULL) {
		mSharedInstance = new TEManagerSound::TEManagerSound();
	}
	return mSharedInstance;
}

void TEManagerSound::moveComponentToTop(TEComponent* component) {}
