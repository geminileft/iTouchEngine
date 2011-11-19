#include "TERenderer.h"

TERenderer::TERenderer() : mTop(0) {}

void TERenderer::addTexture(TEUtilTexture* texture, float* vertexBuffer, float* textureBuffer, TEVec3 position) {
    TERenderPrimative rp;
    rp.texture = texture;
    rp.position = position;
    rp.vertexBuffer = vertexBuffer;
    rp.textureBuffer = textureBuffer;
    mPrimatives[mTop] = rp;
    ++mTop;
}

void TERenderer::reset() {
    glClear(GL_COLOR_BUFFER_BIT);
    mTop = 0;
}

TERenderPrimative* TERenderer::getRenderPrimatives() {
    return mPrimatives;
}

uint TERenderer::getPrimativeCount() const {
    return mTop;
}
