//
//  EAGLView.m
//  OpenGLES_iPhone
//
//  Created by mmalc Crawford on 11/18/10.
//  Copyright 2010 Apple Inc. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>
#import "EAGLView.h"

@implementation EAGLView

@synthesize context;

+ (Class)layerClass
{
    return [CAEAGLLayer class];
}

- (id)initWithFrame:(CGRect)frame game:(TEEngine*) game {
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
        glGenFramebuffers(1, &defaultFramebuffer);
        glBindFramebuffer(GL_FRAMEBUFFER, defaultFramebuffer);
        glGenRenderbuffers(1, &colorRenderbuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, colorRenderbuffer);
        [context renderbufferStorage:GL_RENDERBUFFER fromDrawable:(CAEAGLLayer *)self.layer];
        glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &framebufferWidth);
        glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &framebufferHeight);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, colorRenderbuffer);
        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
            NSLog(@"Failed to make complete framebuffer object %x", glCheckFramebufferStatus(GL_FRAMEBUFFER));        
        glBindFramebuffer(GL_FRAMEBUFFER, defaultFramebuffer);
        glViewport(0, 0, framebufferWidth, framebufferHeight);
        [self startAnimation];
        CAEAGLLayer *eaglLayer = (CAEAGLLayer *)self.layer;
        eaglLayer.opaque = TRUE;
        eaglLayer.drawableProperties = [NSDictionary dictionaryWithObjectsAndKeys:
                                        [NSNumber numberWithBool:FALSE], kEAGLDrawablePropertyRetainedBacking,
                                        kEAGLColorFormatRGBA8, kEAGLDrawablePropertyColorFormat,
                                        nil];
    }
    return self;
}

- (void)dealloc
{
    [context release];
    
    [super dealloc];
}
- (void)startAnimation {
        CADisplayLink *aDisplayLink = [[UIScreen mainScreen] displayLinkWithTarget:self selector:@selector(drawFrame)];
        [aDisplayLink setFrameInterval:1];
        [aDisplayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
}

- (void)drawFrame
{
    static const GLfloat squareVertices[] = {
        -0.5f, -0.33f,
        0.5f, -0.33f,
        -0.5f,  0.33f,
        0.5f,  0.33f,
    };
    
    static const GLubyte squareColors[] = {
        255, 255,   0, 255,
        0,   255, 255, 255,
        0,     0,   0,   0,
        255,   0, 255, 255,
    };
    
    static float transY = 0.0f;
    
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0f, (GLfloat)(sinf(transY)/2.0f), 0.0f);
        transY += 0.075f;
        
        glVertexPointer(2, GL_FLOAT, 0, squareVertices);
        glEnableClientState(GL_VERTEX_ARRAY);
        glColorPointer(4, GL_UNSIGNED_BYTE, 0, squareColors);
        glEnableClientState(GL_COLOR_ARRAY);
    
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    
    [context presentRenderbuffer:GL_RENDERBUFFER];
}




@end
