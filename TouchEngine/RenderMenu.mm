#include "RenderMenu.h"
#include "TEUtilTexture.h"

RenderMenu::RenderMenu(NSString* menuResourceName, NSString* buttonResourceName, TEPoint menuPosition, TEPoint buttonPosition) {
	mPosition = menuPosition;
	mSize.width = 0;
	mSize.height = 0;
    mTexture = new TEUtilTexture(menuResourceName, menuPosition, mSize);
	mSize = mTexture->getBitmapSize();
    mCrop[0] = 0;
    mCrop[1] = mSize.height;
    mCrop[2] = mSize.width;
    mCrop[3] = -mSize.height;
	mParent->position = mPosition;
	mParent->size = mSize;
}

void RenderMenu::update() {
	mParent->position = mPosition;
	mParent->size = mSize;
}

void RenderMenu::draw() {
	glBindTexture(GL_TEXTURE_2D, mTexture->mTextureName);
	
	const bool useDrawTexfOES = false;
	if (useDrawTexfOES) {
		glTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_CROP_RECT_OES, mCrop);
		glDrawTexfOES(mParent->position.x - (mSize.width / 2), mParent->position.y - (mSize.height / 2), 
					  0.001f, mSize.width, mSize.height);
	} else {
		glPushMatrix();
		glTranslatef(mParent->position.x, mParent->position.y, 0.0f);
		glTexCoordPointer(2, GL_FLOAT, 0, mTexture->mTextureBuffer);
		glVertexPointer(2, GL_FLOAT, 0, mTexture->mVertexBuffer);
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
		glPopMatrix();
	}
}
