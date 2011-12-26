#ifndef TOUCHENGINEAPPDELEGATE
#define TOUCHENGINEAPPDELEGATE

class TEEngine;

#import <UIKit/UIKit.h>

@class TouchEngineViewController;

@interface TouchEngineAppDelegate : NSObject <UIApplicationDelegate> {

@private
    UIWindow* mWindow;
    TEEngine* mGame;
}

@end

#endif