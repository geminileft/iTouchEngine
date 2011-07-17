
#include "RenderImage.h"

RenderImage::RenderImage(NSString* resourceName, TEPoint position, TESize size) {
    //addEventSubscription(TEComponent.Event.EVENT_MOVE_TO_TOP, mMoveToTopListener);
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
    glEnable(GL_TEXTURE_2D);
    unsigned int textureName = mTexture->mTextureName;
    TEPoint position;
    //position.x = mParent->position.x;
    //position.y = mParent->position.y;
    position.x = 160;
    position.y = 240;
    glBindTexture(GL_TEXTURE_2D, textureName);
    glTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_CROP_RECT_OES, mCrop);
    glDrawTexfOES(position.x - (mWidth / 2), position.y - (mHeight / 2), 0, mWidth, mHeight);
    glDisable(GL_TEXTURE_2D);
}

/*	
	private TEComponent.EventListener mMoveToTopListener = new TEComponent.EventListener() {
		
		public void invoke() {
			RenderImage.this.getManager().moveComponentToTop(RenderImage.this);
		}
	};
	
	public RenderImage(int resourceId) {
		this(resourceId, null, null);
	}
    
	@Override
	
	public Size getSize() {
		return new Size(mWidth, mHeight);
	}
}
*/