//
//  RenderHUDMoves.cpp
//  TouchEngine
//
//  Created by geminileft on 7/29/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "RenderHUDMoves.h"
#include "TEEventListener.h"

#define MAX_DIGIT_COUNT 4
#define MAX_TEXT_SIZE 18

RenderHUDMoves::RenderHUDMoves(NSString* resourceName, TEPoint position, TESize size) : mCount(0) {
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
	
	width = 9;
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


void RenderHUDMoves::draw() {
	int moveCountDigits[MAX_DIGIT_COUNT];
	for(int i = 0;i < MAX_DIGIT_COUNT;++i) {
		moveCountDigits[i] = 0;
	}
	int digits = 0;
	int number;
	const int radix = 10;
	int count = mCount;
	while ((count > 0) && (digits < MAX_DIGIT_COUNT)) {
		moveCountDigits[digits] = count % radix;
		count /= radix;
		++digits;
	}
	digits = (digits == 0) ? 1 : digits;
	glPushMatrix();
	glTranslatef(mX, mY, 0.0f);
	glBindTexture(GL_TEXTURE_2D, mTexture->mTextureName);
	while (digits > 0) {
		number = moveCountDigits[--digits];
		//glTexCoordPointer(2, GL_FLOAT, 0, mTexture->mTextureBuffer);
		glTexCoordPointer(2, GL_FLOAT, 0, mTextureBuffers[number]);
		//glVertexPointer(2, GL_FLOAT, 0, mTexture->mVertexBuffer);
		glVertexPointer(2, GL_FLOAT, 0, mVertexBuffers[number]);
/*
		glVertexPointer(2, GL_FLOAT, 0, mVertexBuffers[number]);
*/
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
		glTranslatef(MAX_TEXT_SIZE, 0.0f, 0.0f);
	}
	glPopMatrix();
}

void RenderHUDMoves::update() {
	TEPoint point = mParent->position;
	mX = point.x;
	mY = point.y;
}

void RenderHUDMoves::createTextureBuffer(int left, int width, int height, float textureBuffer[]) {
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

void RenderHUDMoves::createVertexBuffer(int width, int height, float vertexBuffer[]) {
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

void RenderHUDMoves::touchAcceptListener() {
	++mCount;
}

TEEventListenerBase* RenderHUDMoves::getTouchAcceptListener() {
	TEEventListener<RenderHUDMoves>* touchAcceptListener = new TEEventListener<RenderHUDMoves>(this, &RenderHUDMoves::touchAcceptListener);
	return touchAcceptListener;
}
