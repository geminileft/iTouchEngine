//
//  TouchEngineAppDelegate.h
//  TouchEngine
//
//  Created by geminileft on 7/16/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

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