//
//  RenderHUDMoves.h
//  TouchEngine
//
//  Created by geminileft on 7/29/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef RENDERHUDMOVES
#define RENDERHUDMOVES

#include "TEComponentRender.h"
#include "TETypes.h"
#include "TEUtilTexture.h"

class RenderHUDMoves : public TEComponentRender {
private:
	float mX;
	float mY;
	int mCount;
	TEUtilTexture* mTexture;
	float mWidth;
	float mHeight;
	float mTextureBuffers[10][8];
	float mVertexBuffers[10][8];

public:
    RenderHUDMoves(NSString* resourceName, TEPoint position, TESize size);
    virtual void update();
    virtual void draw();
	void createTextureBuffer(int left, int width, int height, float textureBuffer[]);
	void createVertexBuffer(int width, int height, float vertexBuffer[]);
	TEEventListenerBase* getTouchAcceptListener();
	void touchAcceptListener();
};

#endif
