#ifndef SOUNDSTART
#define SOUNDSTART

#include "TEComponentSound.h"

class SoundStart : public TEComponentSound {
private:
	NSUInteger mSourceID;
	bool mHasPlayed;

public:
	SoundStart(NSString* resource, NSString* type);
	virtual void update();
};

#endif