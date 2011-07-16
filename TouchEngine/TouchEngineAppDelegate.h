//
//  TouchEngineAppDelegate.h
//  TouchEngine
//
//  Created by geminileft on 7/16/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

#include "FreeCellGame.h"

@class TouchEngineViewController;

@interface TouchEngineAppDelegate : NSObject <UIApplicationDelegate> {

@private
    FreeCellGame mGame;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;

//@property (nonatomic, retain) IBOutlet TouchEngineViewController *viewController;

@end
