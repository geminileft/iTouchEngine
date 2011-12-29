#ifndef TouchEngine_TERenderer_h
#define TouchEngine_TERenderer_h

#include "TETypes.h"

class TEUtilTexture;

#define MAX_RENDER_PRIMATIVES   1000

struct TERenderPrimative {
    TEUtilTexture* texture;
    TEVec3 position;
    float* vertexBuffer;
    float* textureBuffer;
};

typedef TERenderPrimative TERenderPrimative;

class TERenderer {
private:
    uint mTop;
    TERenderPrimative mPrimatives[MAX_RENDER_PRIMATIVES];
    
public:
    TERenderer();
    virtual void render() = 0;
    void addTexture(TEUtilTexture* texture, float* vertexBuffer, float* textureBuffer, TEVec3 position);
    void reset();
    TERenderPrimative* getRenderPrimatives();
    uint getPrimativeCount() const;
};

#endif
