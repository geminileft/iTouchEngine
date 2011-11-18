#include "TERendererOGL2.h"
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#include "TEManagerFile.h"
#include "TEManagerGraphics.h"
#include "TEUtilTexture.h"

#import <QuartzCore/QuartzCore.h>

static std::map<String, uint> mPrograms;

TERendererOGL2::TERendererOGL2(CALayer* layer) {
    mContext = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
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
    checkGlError("prior");
	glDisable(GL_DEPTH_TEST);
    checkGlError("prior");
	glDisable(GL_DITHER);
    checkGlError("prior");
    glEnable(GL_BLEND);
    checkGlError("prior");
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    checkGlError("prior");
    glClearColor(0.2f, 1.0f, 0.2f, 1.0f);
    
    //always drawing textures...enable once
    glViewport(0, 0, mWidth, mHeight);

    createPrograms();
    switchProgram("texture");
}

void TERendererOGL2::createPrograms() {
    std::string vertexShader;
    std::string fragmentShader;
    int program;
    checkGlError("Prior");
    vertexShader = TEManagerFile::readFileContents("texture.vs");
    fragmentShader = TEManagerFile::readFileContents("texture.fs");
    program = createProgram("texture", vertexShader, fragmentShader);
    addProgramAttribute(program, "aPosition");
    addProgramAttribute(program, "aTexture");
    
    vertexShader = TEManagerFile::readFileContents("colorbox.vs");
    fragmentShader = TEManagerFile::readFileContents("colorbox.fs");
    program = createProgram("colorbox", vertexShader, fragmentShader);
    addProgramAttribute(program, "vertices");
    
    vertexShader = TEManagerFile::readFileContents("effectbox.vs");
    fragmentShader = TEManagerFile::readFileContents("colorbox.fs");
    program = createProgram("effectbox", vertexShader, fragmentShader);
    addProgramAttribute(program, "vertices");
}

void TERendererOGL2::render() {
    TERenderPrimative* primatives = getRenderPrimatives();
    uint count = getPrimativeCount();
    TEUtilTexture* texture;
    TEVec3 vec;
    for (int i = 0;i < count;++i) {
        texture = primatives[i].texture;
        vec = primatives[i].position;
        glBindTexture(GL_TEXTURE_2D, texture->mTextureName);	
        //glPushMatrix();
        //glTranslatef(vec.x, vec.y, vec.z);
        glVertexAttribPointer(maTextureHandle, 2, GL_FLOAT, false, 0, primatives[i].textureBuffer);
        glVertexAttribPointer(maPositionHandle, 2, GL_FLOAT, false, 0, primatives[i].vertexBuffer);
        //glVertexPointer(2, GL_FLOAT, 0, primatives[i].textureBuffer);
        //glVertexPointer(2, GL_FLOAT, 0, primatives[i].vertexBuffer);
        glVertexAttrib2f(mCoordsHandle, vec.x, vec.y);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
        checkGlError("draw");
        //glPopMatrix();

    }
    
    [mContext presentRenderbuffer:GL_RENDERBUFFER];
}


int TERendererOGL2::createProgram(String programName, String vertexSource, String fragmentSource) {
    uint program = glCreateProgram();
    //NSAssert(program != 0, @"Failed to create program");
    checkGlError("created program");
    mPrograms[programName] = program;
    uint vertexShader = loadShader(GL_VERTEX_SHADER, vertexSource);
    glAttachShader(program, vertexShader);
    checkGlError("attached shader");
    uint fragmentShader = loadShader(GL_FRAGMENT_SHADER, fragmentSource);
    glAttachShader(program, fragmentShader);
    checkGlError("attached shader");
    glLinkProgram(program);
    checkGlError("linked program");
    int linkStatus[1];
    glGetProgramiv(program, GL_LINK_STATUS, linkStatus);
    if (linkStatus[0] != GL_TRUE) {
        NSLog(@"Error");
        glDeleteProgram(program);
        program = 0;
    }
    return program;
}

void TERendererOGL2::addProgramAttribute(uint program, String attribute) {
    std::list<String> list = mProgramAttributes[program];
    list.push_back(attribute);
    mProgramAttributes[program] = list;
}

uint TERendererOGL2::loadShader(uint shaderType, String source) {
    uint shader = glCreateShader(shaderType);
    if (shader == 0) {
        NSLog(@"Big problem!");
    }
    const char* str = source.c_str();
    glShaderSource(shader, 1, &str, NULL);
    checkGlError("shader source");
    glCompileShader(shader);
    checkGlError("compile source");
    return shader;
}

void TERendererOGL2::switchProgram(String programName) {
    uint program = mPrograms[programName];
    glUseProgram(program);
    checkGlError("glUseProgram");
    
    if (mProgramAttributes.count(program) > 0) {
        std::list<String> list = mProgramAttributes[program];
        std::list<String>::iterator iterator;
        for (iterator = list.begin();iterator != list.end();++iterator) {
            uint positionHandle = getAttributeLocation(program, (*iterator));
            glEnableVertexAttribArray(positionHandle);
            checkGlError("glEnableVertexAttribArray");        		
        }
    }
    
    float projectionMatrix[16];
    TEManagerGraphics::getProjectionMatrix(projectionMatrix);
    float viewMatrix[16];
    TEManagerGraphics::getViewMatrix(viewMatrix);
    
    uint projectionHandle = getUniformLocation(program, "uProjectionMatrix");
    glUniformMatrix4fv(projectionHandle, 1, false, projectionMatrix);
    checkGlError("glUniformMatrix4fv");
    
    const uint viewHandle = getUniformLocation(program, "uViewMatrix");
    glUniformMatrix4fv(viewHandle, 1, false, viewMatrix);
    checkGlError("glUniformMatrix4fv");
    
    mCoordsHandle = getAttributeLocation(program, "aCoords");
    maPositionHandle = getAttributeLocation(program, "aPosition");
    maTextureHandle = getAttributeLocation(program, "aTexture");
}

void TERendererOGL2::checkGlError(String op) {
    uint error;
    while ((error = glGetError()) != GL_NO_ERROR) {
        if (error == GL_INVALID_ENUM) {
            NSLog(@"Bad");
        }
        NSLog(@"Error!!");
    }
}

uint TERendererOGL2::getAttributeLocation(uint program, String attribute) {
    return glGetAttribLocation(program, attribute.c_str());
}

uint TERendererOGL2::getUniformLocation(uint program, String uniform) {
    return glGetUniformLocation(program, uniform.c_str());
}

