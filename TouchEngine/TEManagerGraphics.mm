//
//  TEManagerGraphics.cpp
//  TouchEngine
//
//  Created by developer on 11/7/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include "TEManagerGraphics.h"
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

static unsigned int mRenderBuffer;
static unsigned int mFrameBuffer;
static int mWidth;
static int mHeight;
static EAGLContext* mContext;

void TEManagerGraphics::initialize(CALayer* layer) {
    mContext = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES1];
    if (!mContext)
        NSLog(@"Failed to create ES context");
    else if (![EAGLContext setCurrentContext:mContext])
        NSLog(@"Failed to set ES context current");

    glGenRenderbuffers(1, &mRenderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, mRenderBuffer);
    [mContext renderbufferStorage:GL_RENDERBUFFER fromDrawable:(CAEAGLLayer *)layer];
    glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &mWidth);
    glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &mHeight);

    glGenFramebuffers(1, &mFrameBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, mFrameBuffer);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, mRenderBuffer);
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        NSLog(@"Failed to make complete framebuffer object %x", glCheckFramebufferStatus(GL_FRAMEBUFFER));        
    glBindFramebuffer(GL_FRAMEBUFFER, mFrameBuffer);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_DITHER);
	glDisable(GL_LIGHTING);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.2f, 1.0f, 0.2f, 1.0f);

    //always drawing textures...enable once
    glEnable(GL_TEXTURE_2D);

    //required for vertex/textures
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	bool useOrtho = false;
	const int scaleFactor = 1;
	const int zDepth = mHeight / (2 / scaleFactor);
	const float ratio = (float)mWidth / mHeight;
	glViewport(0, 0, mWidth, mHeight);
	glMatrixMode(GL_PROJECTION);
	if (useOrtho) {
		glOrthof(0.0f, mWidth, 0.0f, mHeight, 0.0f, 1.0f);
	} else {
		glFrustumf(-ratio, ratio, -1, 1, 1, zDepth);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (!useOrtho) {
		glTranslatef(-mWidth / 2, -mHeight / 2, -zDepth);				
	}

}

void TEManagerGraphics::render() {
    [mContext presentRenderbuffer:GL_RENDERBUFFER];
}