//
//  TouchEngineAppDelegate.h
//  TouchEngine
//
//  Created by geminileft on 7/16/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef TOUCHENGINEAPPDELEGATE
#define TOUCHENGINEAPPDELEGATE

#import <UIKit/UIKit.h>

#include "FreeCellGame.h"

@class TouchEngineViewController;

@interface TouchEngineAppDelegate : NSObject <UIApplicationDelegate> {

@private
    UIWindow* mWindow;
    TEEngine* mGame;
}

-(void) drawFrame;

@end

#endif