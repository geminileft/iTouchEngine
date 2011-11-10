#include "RenderImage.h"
#include "TEManagerGraphics.h"

RenderImage::RenderImage(NSString* resourceName, TEPoint position, TESize size) {
	TEEventListener<RenderImage>* moveToTopListener = new TEEventListener<RenderImage>(this, &RenderImage::moveToTopListener);
    addEventSubscription(EVENT_MOVE_TO_TOP, moveToTopListener);
    mTexture = new TEUtilTexture(resourceName, position, size);
    if (size.width == 0 && size.height == 0) {
        size = mTexture->getBitmapSize();
    }
    mWidth = size.width;
    mHeight = size.height;
    mCrop[0] = 0;
    mCrop[1] = mHeight;
    mCrop[2] = mWidth;
    mCrop[3] = -mHeight;
}

void RenderImage::update() {
    TEVec3 vec3;
    vec3.x = mParent->position.x;
    vec3.y = mParent->position.y;
    vec3.z = 0;
    TEManagerGraphics::addTexture(mTexture, vec3);
    
}

void RenderImage::draw() {
}

void RenderImage::moveToTopListener() {
	getManager()->moveComponentToTop(this);
};

TESize RenderImage::getSize() {
	TESize size;
	size.width = mWidth;
	size.height = mHeight;
	return size;
}
