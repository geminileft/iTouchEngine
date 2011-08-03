//
//  TEComponentSound.cpp
//  TouchEngine
//
//  Created by geminileft on 8/3/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TEComponentSound.h"

AudioFileID TEComponentSound::openAudioFile(NSString* filePath) {
	AudioFileID outAFID;
	// use the NSURl instead of a cfurlref cuz it is easier
	NSURL * afUrl = [NSURL fileURLWithPath:filePath];
	
	// do some platform specific stuff..
#if TARGET_OS_IPHONE
	OSStatus result = AudioFileOpenURL((CFURLRef)afUrl, kAudioFileReadPermission, 0, &outAFID);
#else
	OSStatus result = AudioFileOpenURL((CFURLRef)afUrl, fsRdPerm, 0, &outAFID);
#endif
	if (result != 0) NSLog(@"cannot openf file: %@",filePath);
	return outAFID;
}

UInt32 TEComponentSound::audioFileSize(AudioFileID fileDescriptor) {
	UInt64 outDataSize = 0;
	UInt32 thePropSize = sizeof(UInt64);
	OSStatus result = AudioFileGetProperty(fileDescriptor, kAudioFilePropertyAudioDataByteCount, &thePropSize, &outDataSize);
	if(result != 0)
		NSLog(@"cannot find file size");
	return (UInt32)outDataSize;
}
