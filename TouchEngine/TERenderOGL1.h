//
//  TERenderOGL1.h
//  TouchEngine
//
//  Created by developer on 11/9/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef TouchEngine_TERenderOGL1_h
#define TouchEngine_TERenderOGL1_h

#include "TERenderer.h"

class TERendererOGL1 : public TERenderer {
public:
    TERendererOGL1(CALayer* layer);
    virtual void render();
};

#endif
