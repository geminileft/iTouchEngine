//
//  TEManagerSound.h
//  TouchEngine
//
//  Created by geminileft on 8/2/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef TEMANAGERSOUND
#define TEMANAGERSOUND

class TEComponent;

#include "TEManagerComponent.h"
#include <OpenAL/alc.h>
#include <AudioToolbox/AudioToolbox.h>

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