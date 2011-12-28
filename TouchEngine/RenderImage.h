#ifndef RENDERIMAGE
#define RENDERIMAGE

class TEUtilTexture;

#include "TEComponentRender.h"
#include "TETypes.h"

class RenderImage : public TEComponentRender {
private:
	TEUtilTexture* mTexture;
	int mCrop[4];
	int mWidth;
	int mHeight;
    uint mProgram;
    uint mCoordsHandle;
    uint maPositionHandle;
    uint maTextureHandle;


public:
    RenderImage(NSString* resourceName, TEPoint position, TESize size);
    virtual void update();
    virtual void draw();
	void moveToTopListener();
	TESize getSize();
};
#endif
