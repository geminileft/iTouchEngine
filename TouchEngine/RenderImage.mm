#include "RenderImage.h"
#include "TEManagerGraphics.h"
#include "TERenderer.h"
#include "TEUtilTexture.h"
#include "TEGameObject.h"

RenderImage::RenderImage(NSString* resourceName, TEPoint position, TESize size) {    
    mTexture = new TEUtilTexture(resourceName, position, size);
	TEEventListener<RenderImage>* moveToTopListener = new TEEventListener<RenderImage>(this, &RenderImage::moveToTopListener);
    addEventSubscription(EVENT_MOVE_TO_TOP, moveToTopListener);
}

void RenderImage::update() {
    TEVec3 vec3;
    vec3.x = mParent->position.x;
    vec3.y = mParent->position.y;
    vec3.z = 0;
    TEManagerGraphics::getRenderer()->addTexture(mTexture, mTexture->mVertexBuffer, mTexture->mTextureBuffer, vec3);
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
