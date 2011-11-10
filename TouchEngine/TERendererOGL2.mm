#include "TERendererOGL2.h"
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#include "TEManagerFile.h"

#import <QuartzCore/QuartzCore.h>

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
    
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_DITHER);
	glDisable(GL_LIGHTING);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.2f, 1.0f, 0.2f, 1.0f);
    
    //always drawing textures...enable once
    glEnable(GL_TEXTURE_2D);
    glViewport(0, 0, mWidth, mHeight);

    createPrograms();
}

void TERendererOGL2::createPrograms() {
    std::string vertexShader;
    std::string fragmentShader;
    int program;
    
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
    [mContext presentRenderbuffer:GL_RENDERBUFFER];
}


int TERendererOGL2::createProgram(String programName, String vertexSource, String fragmentSource) {
    uint program = glCreateProgram();
    mPrograms[programName] = program;
    uint vertexShader = loadShader(GL_VERTEX_SHADER, vertexSource);
    glAttachShader(program, vertexShader);
    uint fragmentShader = loadShader(GL_FRAGMENT_SHADER, fragmentSource);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
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
    std::list<String> list;
    if (mProgramAttributes.count(program) > 0) {
        list = mProgramAttributes[program];
    } else {
        mProgramAttributes[program] = list;
    }
    list.push_back(attribute);
}

uint TERendererOGL2::loadShader(uint shaderType, String source) {
    uint shader = glCreateShader(shaderType);
    const char* str = source.c_str();
    int len = source.length();
    glShaderSource(shader, 1, &str, &len);
    glCompileShader(shader);
    return shader;
}

