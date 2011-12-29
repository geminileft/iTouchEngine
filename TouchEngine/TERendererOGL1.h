#ifndef TouchEngine_TERenderOGL1_h
#define TouchEngine_TERenderOGL1_h

#include "TERenderer.h"

class TERendererOGL1 : public TERenderer {
private:
    EAGLContext* mContext;
    unsigned int mRenderBuffer;
    unsigned int mFrameBuffer;
    int mWidth;
    int mHeight;
    
public:
    TERendererOGL1(CALayer* layer);
    virtual void render();
};

#endif
