
#include "RenderImage.h"

RenderImage::RenderImage(string imageName, TEPoint position, TESize size) {
/*
    super();
    addEventSubscription(TEComponent.Event.EVENT_MOVE_TO_TOP, mMoveToTopListener);
    mTexture = new TEUtilTexture(resourceId, position, size);
    if (size == null) {
        size = mTexture.getBitmapSize();
    }
    mWidth = size.width;
    mHeight = size.height;
    mGL = TEManagerGraphics.getGL();
    mCrop[0] = 0;
    mCrop[1] = mHeight;
    mCrop[2] = mWidth;
    mCrop[3] = -mHeight;
*/
}


void RenderImage::update() {}

void RenderImage::draw() {
/*
    mGL.glBindTexture(GL10.GL_TEXTURE_2D, mTexture.textureName);
    //((GL11)mGL).glGetTexParameteriv(GL10.GL_TEXTURE_2D, GL11Ext.GL_TEXTURE_CROP_RECT_OES, mLastCrop, 0);        
    ((GL11)mGL).glTexParameteriv(GL10.GL_TEXTURE_2D, GL11Ext.GL_TEXTURE_CROP_RECT_OES, mCrop, 0);
    ((GL11Ext)mGL).glDrawTexfOES(parent.position.x - (mWidth / 2), parent.position.y - (mHeight / 2), 
                                 0, mWidth, mHeight);
*/
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