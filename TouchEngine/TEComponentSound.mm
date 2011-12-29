#include "TEComponentSound.h"

AudioFileID TEComponentSound::openAudioFile(NSString* filePath) {
	AudioFileID outAFID;
	// use the NSURl instead of a cfurlref cuz it is easier
	NSURL * afUrl = [NSURL fileURLWithPath:filePath];
	
	OSStatus result = AudioFileOpenURL((CFURLRef)afUrl, kAudioFileReadPermission, 0, &outAFID);
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
