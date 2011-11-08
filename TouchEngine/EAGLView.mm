//
//  EAGLView.m
//  OpenGLES_iPhone
//
//  Created by mmalc Crawford on 11/18/10.
//  Copyright 2010 Apple Inc. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>
#import "EAGLView.h"

#include "TEInputTouch.h"
#include "TEManagerInput.h"
#include "TEManagerTime.h"
#include "TEManagerGraphics.h"

@implementation EAGLView

+ (Class)layerClass
{
    return [CAEAGLLayer class];
}

- (id)initWithFrame:(CGRect)frame game:(TEEngine*) game {
	const int scaleFactor = 1;
	frame.size.width = game->mWidth * scaleFactor;
	frame.size.height = game->mHeight * scaleFactor;
    self = [super initWithFrame:frame];
	if (self) {
        mGame = game;
        mContext = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES1];
        if (!mContext)
            NSLog(@"Failed to create ES context");
        else if (![EAGLContext setCurrentContext:mContext])
            NSLog(@"Failed to set ES context current");
        TEManagerGraphics::initialize(mContext, self.layer);
        [self startAnimation];
    }
    return self;
}

- (void)dealloc
{
    [mContext release];
    
    [super dealloc];
}

- (void)startAnimation {
    mGame->start();
	mPreviousInterval = TEManagerTime::currentTime();
    CADisplayLink *aDisplayLink = [[UIScreen mainScreen] displayLinkWithTarget:self selector:@selector(drawFrame)];
    [aDisplayLink setFrameInterval:1];
    [aDisplayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
}

- (void)drawFrame {
/*
	long currentTime = TEManagerTime::currentTime();
	long difference = currentTime - mPreviousInterval;
	NSLog(@"frame: %ld", difference);
	mPreviousInterval = currentTime;
*/
    glClear(GL_COLOR_BUFFER_BIT);
    mGame->run();
    [mContext presentRenderbuffer:GL_RENDERBUFFER];
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
    TEManagerInput* inputManager = TEManagerInput::sharedManager();
    CGRect screenSize = [[UIScreen mainScreen] bounds];
    for (UITouch* touch in touches) {
        CGPoint point = [touch locationInView:self];
        float x = point.x;
        float y = screenSize.size.height - point.y;
        TEInputTouch* inputTouch = new TEInputTouch([touch hash], x, y);
        inputManager->beginTouch(inputTouch);
    }
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event {
    TEManagerInput* inputManager = TEManagerInput::sharedManager();
    CGRect screenSize = [[UIScreen mainScreen] bounds];
    for (UITouch* touch in touches) {
        CGPoint point = [touch locationInView:self];
        float x = point.x;
        float y = screenSize.size.height - point.y;	
        TEInputTouch* inputTouch = new TEInputTouch([touch hash], x, y);
        inputManager->moveTouch(inputTouch);
    }
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
    TEManagerInput* inputManager = TEManagerInput::sharedManager();
    CGRect screenSize = [[UIScreen mainScreen] bounds];
    for (UITouch* touch in touches) {
        CGPoint point = [touch locationInView:self];
        float x = point.x;
        float y = screenSize.size.height - point.y;	
        TEInputTouch* inputTouch = new TEInputTouch([touch hash], x, y);
        inputManager->endTouch(inputTouch);
    }
}

@end
