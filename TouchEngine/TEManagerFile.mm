#include "TEManagerFile.h"

String TEManagerFile::readFileContents(String filename) {
    NSBundle* bundle = [NSBundle mainBundle];
    NSString* resourcePath = [bundle resourcePath];
    NSString* resource = [NSString stringWithCString:filename.c_str() encoding:NSUTF8StringEncoding];
    NSString* fullpath = [resourcePath stringByAppendingPathComponent:resource];
    NSString* contents = [NSString stringWithContentsOfFile:fullpath encoding:NSUTF8StringEncoding error:nil];
    const char* c_str = [contents UTF8String];
    String str = String(c_str);
    return str;
}
