#ifndef TOUCHENGINEAPPDELEGATE
#define TOUCHENGINEAPPDELEGATE

#import <UIKit/UIKit.h>

class TEEngine;
@class TouchEngineViewController;

@interface TouchEngineAppDelegate : NSObject <UIApplicationDelegate> {

@private
    UIWindow* mWindow;
    TEEngine* mGame;
}

@end

#endif