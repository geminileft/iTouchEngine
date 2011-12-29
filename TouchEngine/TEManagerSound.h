#ifndef TEMANAGERSOUND
#define TEMANAGERSOUND

#include "TEManagerComponent.h"
#include <OpenAL/alc.h>
#include <AudioToolbox/AudioToolbox.h>

class TEComponent;

class TEManagerSound : public TEManagerComponent {
private:
	ALCcontext* mContext;
	ALCdevice* mDevice;

public:
	TEManagerSound();
	static TEManagerSound* sharedManager();
	virtual void moveComponentToTop(TEComponent* component);
};

#endif