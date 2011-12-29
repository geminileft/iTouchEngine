#include "TEManagerGraphics.h"
#include "TERenderer.h"
#include "TERendererOGL1.h"
#include "TERendererOGL2.h"

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
    //mRenderer = new TERendererOGL1(layer);
    mRenderer = new TERendererOGL2(layer);
}

void TEManagerGraphics::resetRenderer() {
    mRenderer->reset();
}

TERenderer* TEManagerGraphics::getRenderer() {
    return mRenderer;
}

