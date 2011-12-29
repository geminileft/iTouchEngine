#include "TEUtilTexture.h"
#include "TEManagerTexture.h"

TEUtilTexture::TEUtilTexture(NSString* resourceName, TEPoint position, TESize size) :
mBitmapWidth(0), mBitmapHeight(0) {
    UIImage* image = [UIImage imageNamed:resourceName];
    
	float left;
	if (position.x != 0 || position.y != 0) {
		left = position.x / size.width;
	} else {
		left = 0;
	}
	float width;
	float height;
	if (size.height != 0 || size.width != 0) {
		width = size.width;
		height = size.height;
	} else {
		width = image.size.width;
		height = image.size.height;
	}
	
	const float maxS = ((float)width / image.size.width) + left;
	const float maxT = (float)height / image.size.height;
	
	mTextureBuffer[0] = left;//left
	mTextureBuffer[1] = maxT;//top
	mTextureBuffer[2] = maxS;//right
	mTextureBuffer[3] = maxT;//top
	mTextureBuffer[4] = maxS;//right
	mTextureBuffer[5] = 0.0f;//bottom
	mTextureBuffer[6] = left;//left
	mTextureBuffer[7] = 0.0f;//bottom
    
	const float leftX = -(float)width / 2;
	const float rightX = leftX + width;
	const float bottomY = -(float)height / 2;
	const float topY = bottomY + height;
	
	mVertexBuffer[0] = leftX;
	mVertexBuffer[1] = bottomY;
	mVertexBuffer[2] = rightX;
	mVertexBuffer[3] = bottomY;
	mVertexBuffer[4] = rightX;
	mVertexBuffer[5] = topY;
	mVertexBuffer[6] = leftX;
	mVertexBuffer[7] = topY;
    
    CGImage* cImage = [image CGImage];
    mBitmapWidth = CGImageGetWidth(cImage);
    mBitmapHeight = CGImageGetHeight(cImage);
    mTextureName = TEManagerTexture::GLUtexImage2D(cImage);
}

TESize TEUtilTexture::getBitmapSize() const {
	/**********************
	 HACKATHON!!! WTF!!
	 *********************/
    TESize size3;
	TESize size2;
	size3.width = mBitmapWidth;
	size3.height = mBitmapHeight;
	size2.width = 15;
	size2.height = 30;
    return size3;
}

TESize TEUtilTexture::getCropSize() const {
    TESize size;
    size.width = mCropWidth;
    size.height = mCropHeight;
    return size;
}
