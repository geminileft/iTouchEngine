//
//  TERenderOGL1.cpp
//  TouchEngine
//
//  Created by developer on 11/9/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include "TERenderOGL1.h"
#import <QuartzCore/QuartzCore.h>

EAGLContext* mContext;
static unsigned int mRenderBuffer;
static unsigned int mFrameBuffer;

TERendererOGL1::TERendererOGL1(CALayer* layer) {
    mContext = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES1];
    if (!mContext)
        NSLog(@"Failed to create ES context");
    else if (![EAGLContext setCurrentContext:mContext])
        NSLog(@"Failed to set ES context current");

    glGenRenderbuffers(1, &mRenderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, mRenderBuffer);
    [mContext renderbufferStorage:GL_RENDERBUFFER fromDrawable:(CAEAGLLayer *)layer];

    glGenFramebuffers(1, &mFrameBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, mFrameBuffer);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, mRenderBuffer);
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        NSLog(@"Failed to make complete framebuffer object %x", glCheckFramebufferStatus(GL_FRAMEBUFFER));        
    glBindFramebuffer(GL_FRAMEBUFFER, mFrameBuffer);
}

void TERendererOGL1::render() {
    [mContext presentRenderbuffer:GL_RENDERBUFFER];
}