#ifndef TECOMPONENTSOUND
#define TECOMPONENTSOUND

#include "TEComponent.h"
#include <OpenAL/al.h>
#include <AudioToolbox/AudioToolbox.h>

class TEComponentSound : public TEComponent {
public:
	AudioFileID openAudioFile(NSString* filePath);
	UInt32 audioFileSize(AudioFileID fileDescriptor);
};

#endif