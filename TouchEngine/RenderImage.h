#ifndef RENDERIMAGE
#define RENDERIMAGE

#include "TEComponentRender.h"
#include "TETypes.h"
#include <string>

using namespace std;

class RenderImage : public TEComponentRender {
private:
/*
	private int mWidth;
	private int mHeight;
	float mX = 0;
	float mY = 0;
	private TEUtilTexture mTexture;
	private GL10 mGL;
	private int[] mCrop = new int[4];
*/
public:
    RenderImage(string imageName, TEPoint position, TESize size);

    virtual void update();
    virtual void draw();
};
#endif
