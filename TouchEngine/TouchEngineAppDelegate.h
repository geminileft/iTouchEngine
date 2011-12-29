#ifndef TOUCHENGINEAPPDELEGATE
#define TOUCHENGINEAPPDELEGATE

#import <UIKit/UIKit.h>

class TEEngine;
@class TouchEngineViewController;

@interface TouchEngineAppDelegate : NSObject <UIApplicationDelegate> {

@private
    TEEngine* mGame;
}

@end

#endif