#ifndef RENDERHUD
#define RENDERHUD

#include "TEComponentRender.h"
#include "TETypes.h"

class TEUtilTexture;

#define MAX_DIGIT_COUNT 5

class RenderHUD : public TEComponentRender {
private:
	float mX;
	float mY;
	int mCount;
	TEUtilTexture* mTexture;
	float mWidth;
	float mHeight;
	float mTextureBuffers[11][8];
	float mVertexBuffers[11][8];
	long mElapsedTime;
	long mPreviousTime;
    int mMoveCountDigits[MAX_DIGIT_COUNT];
    uint mMoveDigits;
    int mSecondsDigits[MAX_DIGIT_COUNT];

public:
    RenderHUD(NSString* resourceName, TEPoint position, TESize size);
    virtual void update();
    virtual void draw();
	void createTextureBuffer(int left, int width, int height, float textureBuffer[]);
	void createVertexBuffer(int width, int height, float vertexBuffer[]);
	TEEventListenerBase* getTouchAcceptListener();
	void touchAcceptListener();
};

#endif
