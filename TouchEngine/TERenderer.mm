#include "TERenderer.h"

TERenderer::TERenderer() : mTop(0) {}

void TERenderer::addTexture(TEUtilTexture* texture, TEVec3 position) {
    TERenderPrimative rp;
    rp.texture = texture;
    rp.position = position;
    mPrimatives[mTop] = rp;
    ++mTop;
}

void TERenderer::reset() {
    glClear(GL_COLOR_BUFFER_BIT);
    mTop = 0;
}