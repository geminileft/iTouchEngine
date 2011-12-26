//
//  EAGLView.m
//  OpenGLES_iPhone
//
//  Created by mmalc Crawford on 11/18/10.
//  Copyright 2010 Apple Inc. All rights reserved.
//

#import "EAGLView.h"
#import <QuartzCore/QuartzCore.h>

#include "TEEngine.h"
#include "TEInputTouch.h"
#include "TEManagerInput.h"
#include "TEManagerTime.h"
#include "TEManagerGraphics.h"

@implementation EAGLView

+ (Class)layerClass {
    return [CAEAGLLayer class];
}

- (id)initWithFrame:(CGRect)frame game:(TEEngine*) game {
    self = [super initWithFrame:frame];
	if (self) {
        mGame = game;
        TEManagerGraphics::initialize(self.layer, mGame->mWidth, mGame->mHeight);
        mGame->start();
        CADisplayLink *aDisplayLink = [[UIScreen mainScreen] displayLinkWithTarget:self selector:@selector(drawFrame)];
        [aDisplayLink setFrameInterval:1];
        [aDisplayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    }
    return self;
}

- (void)dealloc
{
    [super dealloc];
}

- (void)viewDidAppear:(BOOL)animated {
    NSLog(@"viewDidAppear");
}

- (void)drawFrame {
    mGame->run();
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
