//
//  TEManagerGraphics.h
//  TouchEngine
//
//  Created by developer on 11/7/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef TouchEngine_TEManagerGraphics_h
#define TouchEngine_TEManagerGraphics_h

#include "TETypes.h"

class TEUtilTexture;
class TERenderer;

class TEManagerGraphics {
public:
    static void initialize(CALayer* layer);
    static void render();
    static void addTexture(TEUtilTexture* texture, float* vertexBuffer, float* textureBuffer, TEVec3 position);
    static void resetRenderer();
    static TERenderer* getRenderer();
};

#endif
