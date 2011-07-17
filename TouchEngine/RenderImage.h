#ifndef RENDERIMAGE
#define RENDERIMAGE

#include "TEComponentRender.h"
#include "TETypes.h"
#include "TEUtilTexture.h"

class RenderImage : public TEComponentRender {
private:
	TEUtilTexture* mTexture;
	int mCrop[4];
	int mWidth;
	int mHeight;
    /*
	float mX = 0;
	float mY = 0;
	private GL10 mGL;
*/
public:
    RenderImage(NSString* resourceName, TEPoint position, TESize size);

    virtual void update();
    virtual void draw();
};
#endif
