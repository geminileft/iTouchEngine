//
//  TouchEngineAppDelegate.m
//  TouchEngine
//
//  Created by geminileft on 7/16/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "TouchEngineAppDelegate.h"
#import "EAGLView.h"
#import "TEManagerGraphics.h"
#import <QuartzCore/QuartzCore.h>

@implementation TouchEngineAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    CGRect frame = [[UIScreen mainScreen] bounds];
    EAGLView* view = [[EAGLView alloc] initWithFrame:frame];
    mWindow = [[UIWindow alloc] initWithFrame:frame];
    UIViewController* vc = [[UIViewController alloc] init];
    vc.view = view;
    mWindow.rootViewController = vc;
    
    mGame = new FreeCellGame(frame.size.width, frame.size.height);
    mGame->initializeIOS(view.layer);

    CADisplayLink *aDisplayLink = [[UIScreen mainScreen] displayLinkWithTarget:self selector:@selector(drawFrame)];
    [aDisplayLink setFrameInterval:1];
    [aDisplayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];

    [mWindow makeKeyAndVisible];
    return YES;
}

- (void)drawFrame {
    mGame->run();
}

- (void)dealloc
{
    [mWindow release];
    delete mGame;
    [super dealloc];
}

@end
