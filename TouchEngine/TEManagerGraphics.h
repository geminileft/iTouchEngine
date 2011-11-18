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
    static void initialize(CALayer* layer, float width, float height);
    static void render();
    static void resetRenderer();
    static TERenderer* getRenderer();
    static void getProjectionMatrix(float projectionMatrix[]);
    static void getViewMatrix(float viewMatrix[]);
};

#endif
