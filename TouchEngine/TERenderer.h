//
//  TERenderer.h
//  TouchEngine
//
//  Created by developer on 11/9/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef TouchEngine_TERenderer_h
#define TouchEngine_TERenderer_h

class TEUtilTexture;

#include "TETypes.h"

#define MAX_RENDER_PRIMATIVES   1000

struct TERenderPrimative {
    TEUtilTexture* texture;
    TEVec3 position;
};

typedef TERenderPrimative TERenderPrimative;

class TERenderer {
private:
    uint mTop;
    TERenderPrimative mPrimatives[MAX_RENDER_PRIMATIVES];
    
public:
    TERenderer();
    virtual void render() = 0;
    void addTexture(TEUtilTexture* texture, TEVec3 position);
    void reset();
};

#endif
