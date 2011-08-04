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

@implementation EAGLView

@synthesize context;

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
        EAGLContext *aContext = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES1];
        if (!aContext)
            NSLog(@"Failed to create ES context");
        else if (![EAGLContext setCurrentContext:aContext])
            NSLog(@"Failed to set ES context current");
        self.context = aContext;
        [aContext release];
        glGenFramebuffers(1, &mDefaultFramebuffer);
        glBindFramebuffer(GL_FRAMEBUFFER, mDefaultFramebuffer);
        glGenRenderbuffers(1, &mColorRenderbuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, mColorRenderbuffer);
        [context renderbufferStorage:GL_RENDERBUFFER fromDrawable:(CAEAGLLayer *)self.layer];
        glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &mFramebufferWidth);
        glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &mFramebufferHeight);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, mColorRenderbuffer);
        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
            NSLog(@"Failed to make complete framebuffer object %x", glCheckFramebufferStatus(GL_FRAMEBUFFER));        
        glBindFramebuffer(GL_FRAMEBUFFER, mDefaultFramebuffer);
        CAEAGLLayer *eaglLayer = (CAEAGLLayer *)self.layer;
        eaglLayer.opaque = TRUE;
        eaglLayer.drawableProperties = [NSDictionary dictionaryWithObjectsAndKeys:
                                        [NSNumber numberWithBool:FALSE], kEAGLDrawablePropertyRetainedBacking,
                                        kEAGLColorFormatRGBA8, kEAGLDrawablePropertyColorFormat,
                                        nil];
        mGame->initGraphics(mFramebufferWidth, mFramebufferHeight);
        [self startAnimation];
    }
    return self;
}

- (void)dealloc
{
    [context release];
    
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
    [context presentRenderbuffer:GL_RENDERBUFFER];
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
