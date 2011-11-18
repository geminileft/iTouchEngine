//
//  TEManagerTexture.h
//  TouchEngine
//
//  Created by developer on 11/17/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef TouchEngine_TEManagerTexture_h
#define TouchEngine_TEManagerTexture_h

#include "TETypes.h"
#include "TEUtilsMath.h"

#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

class TEManagerTexture {
public:
    static uint GLUtexImage2D(CGImageRef cgImage);

};

#endif
