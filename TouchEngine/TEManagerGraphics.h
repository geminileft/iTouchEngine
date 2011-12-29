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
};

#endif
