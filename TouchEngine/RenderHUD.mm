#include "RenderHUD.h"
#include "TEEventListener.h"
#include "TEManagerTime.h"
#include "TEManagerGraphics.h"
#include "TERenderer.h"
#include "TEUtilTexture.h"

#define MAX_TEXT_SIZE 18

RenderHUD::RenderHUD(NSString* resourceName, TEPoint position, TESize size) :
	mCount(0), mElapsedTime(0), mPreviousTime(TEManagerTime::currentTime()) {
	mTexture = new TEUtilTexture(resourceName, position, size);
    if (size.width == 0 && size.height == 0) {
        size.width = mTexture->getBitmapSize().width;
		size.height = mTexture->getBitmapSize().height;
    }
	mWidth = size.width;
	mHeight = size.height;
	
	int x = 0;
	int width = 17;
	const int height = 26;
	
	createTextureBuffer(x, width, height, mTextureBuffers[0]);
	x += width;
	width = 14;
	createTextureBuffer(x, width, height, mTextureBuffers[1]);
	x += width;
	width = 17;
	createTextureBuffer(x, width, height, mTextureBuffers[2]);
	x += width;
	createTextureBuffer(x, width, height, mTextureBuffers[3]);
	x += width;
	width = 18;
	createTextureBuffer(x, width, height, mTextureBuffers[4]);
	x += width;
	width = 17;
	createTextureBuffer(x, width, height, mTextureBuffers[5]);
	x += width;
	createTextureBuffer(x, width, height, mTextureBuffers[6]);
	x += width;
	createTextureBuffer(x, width, height, mTextureBuffers[7]);
	x += width;
	createTextureBuffer(x, width, height, mTextureBuffers[8]);
	x += width;
	createTextureBuffer(x, width, height, mTextureBuffers[9]);
	x += width;
	width = 9;
	createTextureBuffer(x, width, height, mTextureBuffers[10]);

	width = 9;
	createVertexBuffer(width, height, mVertexBuffers[10]);
	width = 14;
	createVertexBuffer(width, height, mVertexBuffers[1]);
	width = 17;
	createVertexBuffer(width, height, mVertexBuffers[0]);
	createVertexBuffer(width, height, mVertexBuffers[2]);
	createVertexBuffer(width, height, mVertexBuffers[3]);
	createVertexBuffer(width, height, mVertexBuffers[5]);
	createVertexBuffer(width, height, mVertexBuffers[6]);
	createVertexBuffer(width, height, mVertexBuffers[7]);
	createVertexBuffer(width, height, mVertexBuffers[8]);
	createVertexBuffer(width, height, mVertexBuffers[9]);
	width = 18;
	createVertexBuffer(width, height, mVertexBuffers[4]);
}

void RenderHUD::update() {
	long currentTime = TEManagerTime::currentTime();
	mElapsedTime += currentTime - mPreviousTime;
	mPreviousTime = currentTime;
	TEPoint point = mParent->position;
	mX = point.x;
	mY = point.y;
	for(int i = 0;i < MAX_DIGIT_COUNT;++i) {
		mMoveCountDigits[i] = 0;
	}
	mMoveDigits = 0;
	const int radix = 10;
	int count = mCount;
    int number;
	while ((count > 0) && (mMoveDigits < MAX_DIGIT_COUNT)) {
		mMoveCountDigits[mMoveDigits] = count % radix;
		count /= radix;
		++mMoveDigits;
	}
	mMoveDigits = (mMoveDigits == 0) ? 1 : mMoveDigits;

    int xAdd = 0;
    while (mMoveDigits > 0) {
		number = mMoveCountDigits[--mMoveDigits];
        TEVec3 vec3;
        vec3.x = mParent->position.x + xAdd;
        vec3.y = mParent->position.y;
        vec3.z = 0;
        TEManagerGraphics::getRenderer()->addTexture(mTexture, mVertexBuffers[number], mTextureBuffers[number], vec3);
        xAdd += MAX_TEXT_SIZE;
	}
	const int seconds_size = 2;
	const int minute_size = 2;
	const int secondsDigitsSize = seconds_size + minute_size + 1;
	
	for(int i = 0;i < secondsDigitsSize;++i) {
		mSecondsDigits[i] = 0;
	}
	
	uint digits = 0;
    
	long seconds = (mElapsedTime / 1000) % 60;
	while ((digits < seconds_size)) {
		mSecondsDigits[digits] = (int)seconds % radix;
		seconds /= radix;
		++digits;
	}
	mSecondsDigits[digits] = 10;
	++digits;
	
	int minutes = (int)mElapsedTime / 60000;
	while ((minutes > 0) && (digits < seconds_size + minute_size + 1)) {
		mSecondsDigits[digits] = (int)minutes % radix;
		minutes /= radix;
		++digits;
	}
	digits = (digits < 4) ? 4 : digits;
    
    float x = 50 + mX + (MAX_TEXT_SIZE * (seconds_size + minute_size));
	for(int i = 0;i < digits;i++) {
		number = mSecondsDigits[i];
        TEVec3 vec3;
        vec3.x = x;
        vec3.y = mParent->position.y;
        vec3.z = 0;
        TEManagerGraphics::getRenderer()->addTexture(mTexture, mVertexBuffers[number], mTextureBuffers[number], vec3);
        x -= MAX_TEXT_SIZE;
    }
}

void RenderHUD::draw() {
}

void RenderHUD::createTextureBuffer(int left, int width, int height, float textureBuffer[]) {
	const float minS = (float)left / 256;
	const float maxS = ((float)(width + left) / 256);
	const float maxT = (float)height / 32;

	textureBuffer[0] = minS;//left
	textureBuffer[1] = maxT;//top
	textureBuffer[2] = maxS;//right
	textureBuffer[3] = maxT;//top
	textureBuffer[4] = maxS;//right
	textureBuffer[5] = 0.0f;//bottom
	textureBuffer[6] = minS;//left
	textureBuffer[7] = 0.0f;//bottom	
}

void RenderHUD::createVertexBuffer(int width, int height, float vertexBuffer[]) {
	const float leftX = -(float)width / 2;
	const float rightX = leftX + width;
	const float bottomY = -(float)height / 2;
	const float topY = bottomY + height;
	
	vertexBuffer[0] = leftX;
	vertexBuffer[1] = bottomY;
	vertexBuffer[2] = rightX;
	vertexBuffer[3] = bottomY;
	vertexBuffer[4] = rightX;
	vertexBuffer[5] = topY;
	vertexBuffer[6] = leftX;
	vertexBuffer[7] = topY;
}

void RenderHUD::touchAcceptListener() {
	++mCount;
}

TEEventListenerBase* RenderHUD::getTouchAcceptListener() {
	TEEventListener<RenderHUD>* touchAcceptListener = new TEEventListener<RenderHUD>(this, &RenderHUD::touchAcceptListener);
	return touchAcceptListener;
}
