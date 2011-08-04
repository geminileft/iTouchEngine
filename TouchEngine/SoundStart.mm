//
//  SoundStart.cpp
//  TouchEngine
//
//  Created by geminileft on 8/2/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "SoundStart.h"
#include <OpenAL/al.h>
#include <AudioToolbox/AudioToolbox.h>

SoundStart::SoundStart(NSString* resource, NSString* type) {
	NSString* fileName = [[NSBundle mainBundle] pathForResource:resource ofType:type];
	AudioFileID fileID = openAudioFile(fileName);
	UInt32 fileSize = audioFileSize(fileID);
	void* outData = malloc(fileSize);
	OSStatus result = noErr;
	result = AudioFileReadBytes(fileID, false, 0, &fileSize, outData);
	AudioFileClose(fileID); //close the file
	if (result != 0) NSLog(@"cannot load effect: %@",fileName);
	NSUInteger bufferID;
	alGenBuffers(1, &bufferID);
	alBufferData(bufferID,AL_FORMAT_STEREO16,outData,fileSize,44100); 
	alGenSources(1, &mSourceID); 
	alSourcei(mSourceID, AL_BUFFER, bufferID);
	alSourcef(mSourceID, AL_PITCH, 1.0f);
	alSourcef(mSourceID, AL_GAIN, 1.0f);
	bool loops = false;
	if (loops) alSourcei(mSourceID, AL_LOOPING, AL_TRUE);
	if (outData)
	{
		free(outData);
		outData = NULL;
	}
}

void SoundStart::update() {
	if (!mHasPlayed) {
		alSourcePlay(mSourceID);
		mHasPlayed = true;
	}
}
