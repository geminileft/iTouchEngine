//
//  TERendererOGL2.h
//  TouchEngine
//
//  Created by developer on 11/9/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef TouchEngine_TERendererOGL2_h
#define TouchEngine_TERendererOGL2_h

#include "TERenderer.h"
#include "TETypes.h"
#include <map>
#include <list>

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
    std::map<uint, std::list<String> > mProgramAttributes;
    
    void createPrograms();
    void addProgramAttribute(uint program, String attribute);
    static uint loadShader(uint shaderType, String source);
    void switchProgram(String programName);
    static void checkGlError(String op);

public:
    TERendererOGL2(CALayer* layer);
    static int createProgram(String programName, String vertexSource, String fragmentSource);
    virtual void render();
    static uint getAttributeLocation(uint program, String attribute);
    static uint getUniformLocation(uint program, String uniform);
};

#endif
