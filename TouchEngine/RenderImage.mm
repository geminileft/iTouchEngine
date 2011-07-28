#include "RenderImage.h"

RenderImage::RenderImage(NSString* resourceName, TEPoint position, TESize size) {
	//TEEventListener<RenderImage*> moveToTopListener = new TEEventListener<RenderImage*>(&this, &RenderImage::moveToTopListener);
    //addEventSubscription(EVENT_MOVE_TO_TOP, &moveToTopListener);
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

void RenderImage::update() {}

void RenderImage::draw() {
/*
    glBindTexture(GL_TEXTURE_2D, textureName);
    glTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_CROP_RECT_OES, mCrop);
    glDrawTexfOES(position.x - (mWidth / 2), position.y - (mHeight / 2), 0, mWidth, mHeight);
*/
	glBindTexture(GL_TEXTURE_2D, mTexture->mTextureName);
	
	const bool useDrawTexfOES = false;
	if (useDrawTexfOES) {
		glTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_CROP_RECT_OES, mCrop);
		glDrawTexfOES(mParent->position.x - (mWidth / 2), mParent->position.y - (mHeight / 2), 
									 0.001f, mWidth, mHeight);
	} else {
		glPushMatrix();
		glTranslatef(mParent->position.x, mParent->position.y, 0.0f);
		glTexCoordPointer(2, GL_FLOAT, 0, mTexture->mTextureBuffer);
		glVertexPointer(2, GL_FLOAT, 0, mTexture->mVertexBuffer);
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
		glPopMatrix();
	}
}

void RenderImage::moveToTopListener() {
	getManager()->moveComponentToTop(this);
};

/*
void RenderImage::MoveToTopListener::invoke() {
	//TEManager* = getManager();
	//getManager()->moveComponentToTop(this);
};
*/

/*
	public RenderImage(int resourceId) {
		this(resourceId, null, null);
	}
    
	@Override
	
	public Size getSize() {
		return new Size(mWidth, mHeight);
	}
}
*/