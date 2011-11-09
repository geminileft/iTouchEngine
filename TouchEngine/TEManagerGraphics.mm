//
//  TEManagerGraphics.cpp
//  TouchEngine
//
//  Created by developer on 11/7/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include "TEManagerGraphics.h"
#include "TERenderer.h"
#include "TERenderOGL1.h"

#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

static int mWidth;
static int mHeight;
static TERenderer* mRenderer;

static void initRenderer(CALayer* layer);

void TEManagerGraphics::initialize(CALayer* layer) {
    initRenderer(layer);

    glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &mWidth);
    glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &mHeight);

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
    mRenderer->render();
}

void initRenderer(CALayer* layer) {
    mRenderer = new TERendererOGL1(layer);
}