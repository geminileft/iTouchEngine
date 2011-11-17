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
#include "TEUtilMatrix.h"

static TERenderer* mRenderer;
static float mWidth;
static float mHeight;

static void initRenderer(CALayer* layer);

void TEManagerGraphics::initialize(CALayer* layer, float width, float height) {
    mWidth = width;
    mHeight = height;
    initRenderer(layer);
}

void TEManagerGraphics::render() {
    mRenderer->render();
}

void initRenderer(CALayer* layer) {
    mRenderer = new TERendererOGL1(layer);
    //mRenderer = new TERendererOGL2(layer);
}

void TEManagerGraphics::resetRenderer() {
    mRenderer->reset();
}

TERenderer* TEManagerGraphics::getRenderer() {
    return mRenderer;
}

uint TEManagerGraphics::getAttributeLocation(uint program, String attribute) {
    return glGetAttribLocation(program, attribute.c_str());
}

uint TEManagerGraphics::getUniformLocation(uint program, String uniform) {
    return glGetUniformLocation(program, uniform.c_str());
}

void TEManagerGraphics::getProjectionMatrix(float projectionMatrix[]) {
    float ratio = (float)mWidth / mHeight;
    TEUtilMatrix::setFrustrum(projectionMatrix, -ratio, ratio, -1, 1, 1, mHeight / 2);
}

void TEManagerGraphics::getViewMatrix(float viewMatrix[]) {
    if (true) {
        TEUtilMatrix::setIdentity(viewMatrix);
        TEUtilMatrix::setTranslate(viewMatrix, -mWidth / 2, -mHeight / 2, -mHeight / 2);
    } else {
        TEUtilMatrix::setLookAt(viewMatrix, 0, mHeight / 4, 0, 0, 0, 0, 0, 1, 0);
    }
}

