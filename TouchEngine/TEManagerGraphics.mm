//
//  TEManagerGraphics.cpp
//  TouchEngine
//
//  Created by developer on 11/7/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include "TEManagerGraphics.h"
#include "TERenderer.h"
#include "TERenderOGL1.h"
#include "TERendererOGL2.h"

static TERenderer* mRenderer;

static void initRenderer(CALayer* layer);

void TEManagerGraphics::initialize(CALayer* layer) {
    initRenderer(layer);
}

void TEManagerGraphics::render() {
    mRenderer->render();
}

void initRenderer(CALayer* layer) {
    mRenderer = new TERendererOGL1(layer);
    //mRenderer = new TERendererOGL2(layer);
}