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
    EAGLView* view = [[EAGLView alloc] initWithFrame:frame];
    mWindow = [[UIWindow alloc] initWithFrame:frame];
    [mWindow addSubview:view];
    [mWindow makeKeyAndVisible];
    return YES;
}


- (void)dealloc
{
    [super dealloc];
}

@end
