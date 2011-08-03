//
//  SoundStart.h
//  TouchEngine
//
//  Created by geminileft on 8/2/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SOUNDSTART
#define SOUNDSTART

#include "TEComponentSound.h"

class SoundStart : public TEComponentSound {
private:
	//int mSoundId;
	bool mHasPlayed;

public:
	SoundStart(NSString* resource, NSString* type);
	virtual void update();
};

#endif