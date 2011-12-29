#ifndef TOUCHENGINEAPPDELEGATE
#define TOUCHENGINEAPPDELEGATE

#import <UIKit/UIKit.h>

class TEEngine;

@interface TouchEngineAppDelegate : NSObject <UIApplicationDelegate> {

@private
    TEEngine* mGame;
}

@end

#endif