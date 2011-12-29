#include "TERendererOGL1.h"
#include <QuartzCore/QuartzCore.h>
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#include "TEUtilTexture.h"

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
    
	glViewport(0, 0, mWidth, mHeight);

	bool useOrtho = false;
	const int scaleFactor = 1;
	const int zDepth = mHeight / (2 / scaleFactor);
	const float ratio = (float)mWidth / mHeight;
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

void TERendererOGL1::render() {
    TERenderPrimative* primatives = getRenderPrimatives();
    uint count = getPrimativeCount();
    TEUtilTexture* texture;
    TEVec3 vec;
    for (int i = 0;i < count;++i) {
        texture = primatives[i].texture;
        vec = primatives[i].position;
        glBindTexture(GL_TEXTURE_2D, texture->mTextureName);	
        glPushMatrix();
        glTranslatef(vec.x, vec.y, vec.z);
        glTexCoordPointer(2, GL_FLOAT, 0, primatives[i].textureBuffer);
        glVertexPointer(2, GL_FLOAT, 0, primatives[i].vertexBuffer);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
        glPopMatrix();
    }


    [mContext presentRenderbuffer:GL_RENDERBUFFER];
}