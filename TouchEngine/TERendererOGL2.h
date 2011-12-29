#ifndef TouchEngine_TERendererOGL2_h
#define TouchEngine_TERendererOGL2_h

#include "TERenderer.h"
#include "TETypes.h"
#include <map>
#include <list>
#import <QuartzCore/QuartzCore.h>

class TERendererOGL2 : public TERenderer {
private:
    EAGLContext* mContext;
    uint mRenderBuffer;
    uint mFrameBuffer;
    uint mCoordsHandle;
    uint maPositionHandle;
    uint maTextureHandle;
    int mWidth;
    int mHeight;
    uint mTexture;
    std::map<uint, std::list<String> > mProgramAttributes;
    
    void addProgramAttribute(uint program, String attribute);
    uint switchProgram(String programName);
    static void checkGlError(String op);
    
    void renderBasic();
    void renderTexture();
    
public:
    TERendererOGL2(CALayer* eaglLayer);
    virtual void render();
    static uint loadShader(uint shaderType, String source);
    static int createProgram(String programName, String vertexSource, String fragmentSource);
    static uint getAttributeLocation(uint program, String attribute);
    static uint getUniformLocation(uint program, String uniform);
};

#endif
