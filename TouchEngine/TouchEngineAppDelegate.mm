//
//  TouchEngineAppDelegate.m
//  TouchEngine
//
//  Created by geminileft on 7/16/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "TouchEngineAppDelegate.h"
#import "EAGLView.h"

@implementation TouchEngineAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    CGRect frame = [[UIScreen mainScreen] bounds];
    FreeCellGame* game = new FreeCellGame(frame.size.width, frame.size.height);

    EAGLView* view = [[EAGLView alloc] initWithFrame:frame game:game];
    mWindow = [[UIWindow alloc] initWithFrame:frame];
    UIViewController* vc = [[UIViewController alloc] init];
    vc.view = view;
    mWindow.rootViewController = vc;
    //[mWindow addSubview:view];
    [mWindow makeKeyAndVisible];
    return YES;
}


- (void)dealloc
{
    [super dealloc];
}

@end
