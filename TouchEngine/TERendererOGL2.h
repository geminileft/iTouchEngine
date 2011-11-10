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
    unsigned int mRenderBuffer;
    unsigned int mFrameBuffer;
    int mWidth;
    int mHeight;
    std::map<String, uint> mPrograms;
    std::map<uint, std::list<String> > mProgramAttributes;
    
    void createPrograms();
    int createProgram(String programName, String vertexSource, String fragmentSource);
    void addProgramAttribute(uint program, String attribute);
    uint loadShader(uint shaderType, String source);
    void switchProgram(String programName);
    void checkGlError(String op);

public:
    TERendererOGL2(CALayer* layer);
    virtual void render();
};

#endif
