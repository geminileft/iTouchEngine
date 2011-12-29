#include "TERendererOGL2.h"
#include <QuartzCore/QuartzCore.h>
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#include "TEManagerFile.h"
#include "TEManagerGraphics.h"
#include "TEManagerTexture.h"
#include "TEUtilTexture.h"
#include "TEUtilMatrix.h"


static std::map<String, uint> mPrograms;

TERendererOGL2::TERendererOGL2(CALayer* eaglLayer) {
    // Make sure this is the right version!
    mContext = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
    if (!mContext || ![EAGLContext setCurrentContext:mContext]) {
    }
    
    glGenFramebuffersOES(1, &mFrameBuffer);
    glGenRenderbuffersOES(1, &mRenderBuffer);
    
    glBindFramebufferOES(GL_FRAMEBUFFER_OES, mFrameBuffer);
    glBindRenderbufferOES(GL_RENDERBUFFER_OES, mRenderBuffer);
    [mContext renderbufferStorage:GL_RENDERBUFFER_OES fromDrawable:(CAEAGLLayer*)eaglLayer];
    glFramebufferRenderbufferOES(GL_FRAMEBUFFER_OES, GL_COLOR_ATTACHMENT0_OES, GL_RENDERBUFFER_OES, mRenderBuffer);
    
    glGetRenderbufferParameterivOES(GL_RENDERBUFFER_OES, GL_RENDERBUFFER_WIDTH_OES, &mWidth);
    glGetRenderbufferParameterivOES(GL_RENDERBUFFER_OES, GL_RENDERBUFFER_HEIGHT_OES, &mHeight);
        
    if(glCheckFramebufferStatusOES(GL_FRAMEBUFFER_OES) != GL_FRAMEBUFFER_COMPLETE_OES) {
    }
    
    glBindFramebufferOES(GL_FRAMEBUFFER_OES, mFrameBuffer);
    [EAGLContext setCurrentContext:mContext];
    
    glViewport(0, 0, mWidth, mHeight);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

    int program;
    String vertexSource;
    String fragmentSource;
    
    vertexSource = TEManagerFile::readFileContents("texture.vs");
    fragmentSource = TEManagerFile::readFileContents("texture.fs");
    program = TERendererOGL2::createProgram("texture", vertexSource, fragmentSource);
    addProgramAttribute(program, "aVertices");
    addProgramAttribute(program, "aTextureCoords");
    
    vertexSource = TEManagerFile::readFileContents("colorbox.vs");
    fragmentSource = TEManagerFile::readFileContents("colorbox.fs");
    program = TERendererOGL2::createProgram("basic", vertexSource, fragmentSource);
    addProgramAttribute(program, "aVertices");

    UIImage* image = [UIImage imageNamed:@"table_background.png"];
    CGImage* cImage = [image CGImage];
    mTexture = TEManagerTexture::GLUtexImage2D(cImage);
}

void TERendererOGL2::render() {
    glClear(GL_COLOR_BUFFER_BIT);
    renderBasic();
    renderTexture();
    glBindRenderbufferOES(GL_RENDERBUFFER_OES, mRenderBuffer);
    [mContext presentRenderbuffer:GL_RENDERBUFFER_OES];
}

void TERendererOGL2::renderBasic() {
    uint program = switchProgram("basic");

    const float totalSize = 160.0f;
    const float sideSize = totalSize / 2.0f;

    const GLfloat squareVertices[] = {
        -sideSize, -sideSize,//lb
        sideSize,  -sideSize,//rb
        -sideSize,  sideSize,//lt
        sideSize,   sideSize,//rt
    };

    uint m_a_positionHandle = TERendererOGL2::getAttributeLocation(program, "aVertices");
    glVertexAttribPointer(m_a_positionHandle, 2, GL_FLOAT, GL_FALSE, 0, squareVertices);
    
    uint colorHandle = TERendererOGL2::getUniformLocation(program, "aColor");
    glUniform4f(colorHandle, 1.0f, 0.0f, 1.0f, 1.0f);

    uint posHandle = TERendererOGL2::getAttributeLocation(program, "aPosition");
    glVertexAttrib2f(posHandle, -sideSize, 0.0f);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void TERendererOGL2::renderTexture() {
    uint simpleProgram = switchProgram("texture");
    
    uint positionHandle = TERendererOGL2::getAttributeLocation(simpleProgram, "aVertices");
    uint textureHandle = TERendererOGL2::getAttributeLocation(simpleProgram, "aTextureCoords");
    uint coordsHandle = TERendererOGL2::getAttributeLocation(simpleProgram, "aPosition");

    TERenderPrimative* primatives = getRenderPrimatives();
    uint count = getPrimativeCount();
    TEUtilTexture* texture;
    TEVec3 vec;
    for (int i = 0;i < count;++i) {
        texture = primatives[i].texture;
        vec = primatives[i].position;
        glBindTexture(GL_TEXTURE_2D, texture->mTextureName);	
        glVertexAttrib2f(coordsHandle, vec.x, vec.y);
        glVertexAttribPointer(textureHandle, 2, GL_FLOAT, false, 0, primatives[i].textureBuffer);
        glVertexAttribPointer(positionHandle, 2, GL_FLOAT, false, 0, primatives[i].vertexBuffer);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    }
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

uint TERendererOGL2::switchProgram(String programName) {
    uint program = mPrograms[programName];
    glUseProgram(program);
    checkGlError("glUseProgram");
    
    if (mProgramAttributes.count(program) > 0) {
        std::list<String> list = mProgramAttributes[program];
        std::list<String>::iterator iterator;
        for (iterator = list.begin();iterator != list.end();++iterator) {
            uint handle = getAttributeLocation(program, (*iterator));
            glEnableVertexAttribArray(handle);
            checkGlError("glEnableVertexAttribArray");        		
        }
    }
    
    float proj[16];
    float view[16];
    float zDepth = (float)mHeight / 2;
    const float ratio = (float)mWidth/(float)mHeight;
    //todo: figure out why zDepth doesn't quite work with frustum and translate being same
    TEUtilMatrix::setFrustum(&proj[0], ColumnMajor, -ratio, ratio, -1, 1, 1.0f, 1000.0f);
    TEUtilMatrix::setIdentity(&view[0]);
    TEUtilMatrix::setTranslate(&view[0], ColumnMajor, -(float)mWidth / 2, -(float)mHeight / 2, -zDepth);
    uint mProjHandle  = TERendererOGL2::getUniformLocation(program, "uProjectionMatrix");
    uint mViewHandle = TERendererOGL2::getUniformLocation(program, "uViewMatrix");
    glUniformMatrix4fv(mProjHandle, 1, GL_FALSE, &proj[0]);
    glUniformMatrix4fv(mViewHandle, 1, GL_FALSE, &view[0]);
    return program;
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

