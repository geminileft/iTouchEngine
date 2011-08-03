//
//  TEComponentSound.h
//  TouchEngine
//
//  Created by geminileft on 8/2/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//


#ifndef TECOMPONENTSOUND
#define TECOMPONENTSOUND

#include "TEComponent.h"
#include <OpenAL/al.h>
//#include <OpenAL/alc.h>
#include <AudioToolbox/AudioToolbox.h>

class TEComponentSound : public TEComponent {
public:
	AudioFileID openAudioFile(NSString* filePath);
	UInt32 audioFileSize(AudioFileID fileDescriptor);
};

#endif