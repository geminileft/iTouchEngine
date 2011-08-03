//
//  SoundStart.cpp
//  TouchEngine
//
//  Created by geminileft on 8/2/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "SoundStart.h"
#include <OpenAL/al.h>
//#include <OpenAL/alc.h>
#include <AudioToolbox/AudioToolbox.h>

SoundStart::SoundStart(NSString* resource, NSString* type) {
	NSString* fileName = [[NSBundle mainBundle] pathForResource:resource ofType:type];
	AudioFileID fileID = openAudioFile(fileName);
	UInt32 fileSize = audioFileSize(fileID);
	// this is where the audio data will live for the moment
	
	//unsigned char* outData = malloc(fileSize);
	void* outData = malloc(fileSize);
	
	OSStatus result = noErr;
	result = AudioFileReadBytes(fileID, false, 0, &fileSize, outData);
	AudioFileClose(fileID); //close the file
	
	if (result != 0) NSLog(@"cannot load effect: %@",fileName);
	
	NSUInteger bufferID;
	alGenBuffers(1, &bufferID);
	
	alBufferData(bufferID,AL_FORMAT_STEREO16,outData,fileSize,44100); 
	//mBufferStorageArray = [[NSMutableArray alloc] init];
	//[mBufferStorageArray addObject:[NSNumber numberWithUnsignedInteger:bufferID]];
	NSUInteger sourceID;
	
	// grab a source ID from openAL
	alGenSources(1, &sourceID); 
	
	// attach the buffer to the source
	alSourcei(sourceID, AL_BUFFER, bufferID);
	// set some basic source prefs
	alSourcef(sourceID, AL_PITCH, 1.0f);
	alSourcef(sourceID, AL_GAIN, 1.0f);
	
	bool loops = false;
	if (loops) alSourcei(sourceID, AL_LOOPING, AL_TRUE);
	
	alSourcePlay(sourceID);
	
	// store this for future use
	//[mSoundDictionary setObject:[NSNumber numberWithUnsignedInt:sourceID] forKey:@"neatoSound"];	
	
	// clean up the buffer
	if (outData)
	{
		free(outData);
		outData = NULL;
	}
/*
	Context context = TEStaticSettings.getContext();
	SoundPool soundPool = TEManagerAudio.getSoundPool();
	if (soundPool != null) {
		mSoundId = soundPool.load(context, resourceId, 1);			
	}
*/
}

void SoundStart::update() {
	if (!mHasPlayed) {
/*
		SoundPool soundPool = TEManagerAudio.getSoundPool();
		soundPool.play(mSoundId, 1.0f, 1.0f, 1, 0, 1.0f);
		mHasPlayed = true;
 */
	}
}
