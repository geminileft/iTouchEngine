//
//  TERunnable.m
//  TouchEngine
//
//  Created by dev on 12/26/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "TERunnable.h"
#import <QuartzCore/QuartzCore.h>

#include "TEEngine.h"

@implementation TERunnable

-(id) initWithGame:(TEEngine*) game {
    self = [super init];
    if (self) {
        mGame = game;
        CADisplayLink *aDisplayLink = [[UIScreen mainScreen] displayLinkWithTarget:self selector:@selector(run)];
        [aDisplayLink setFrameInterval:1];
        [aDisplayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];

    }
    return self;
}

-(void) run {
    mGame->run();
}

-(void) dealloc {
    [super dealloc];
}

@end
