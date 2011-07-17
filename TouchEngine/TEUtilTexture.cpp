//
//  TEUtilTexture.cpp
//  TouchEngine
//
//  Created by geminileft on 7/16/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TEUtilTexture.h"

TEUtilTexture::TEUtilTexture(std::string imageName, TEPoint position, TESize size) {
    glGenTextures(1, &mTextureName);
    //InputStream is = context.getResources().openRawResource(resourceId);
    glBindTexture(GL_TEXTURE_2D, mTextureName);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); //GL10.GL_REPLACE);
/*
    Bitmap bitmap = null;
    try {
        //BitmapFactory is an Android graphics utility for images
        bitmap = BitmapFactory.decodeStream(is);
        
    } finally {
        //Always clear and close
        try {
            is.close();
            is = null;
        } catch (IOException e) {
        }
    }
    
    final int bitmapHeight = bitmap.getHeight();
    final int bitmapWidth = bitmap.getWidth();
    
    int width;
    int height;
    
    if (size != null) {
        width = size.width;
        height = size.height;
    } else {
        width = bitmapWidth;
        height = bitmapHeight;
    }
    mCropWidth = width;
    mCropHeight = height;
    mBitmapWidth = bitmapWidth;
    mBitmapHeight = bitmapHeight;
    
    final int textureHeight = MathUtils.closestPowerOf2(bitmapHeight);
    final int textureWidth = MathUtils.closestPowerOf2(bitmapWidth);
    if ((bitmapHeight == textureHeight) && (bitmapWidth == textureWidth)) {
        glTexImage2D(GL10.GL_TEXTURE_2D, 0, bitmap, 0);			
    } else {
        Bitmap adjustedBitmap = Bitmap.createScaledBitmap(bitmap, textureHeight, textureWidth, false);
        GLUtils.texImage2D(GL10.GL_TEXTURE_2D, 0, adjustedBitmap, 0);
        adjustedBitmap.recycle();
    }
    bitmap.recycle();
    final int arraySize = 8;
    final int floatSize = 4;
    
    float left;
    if (position != null) {
        left = position.x / textureWidth;
    } else {
        left = 0;
    }
    
    final float maxS = ((float)width / bitmapWidth) + left;
    final float maxT = (float)height / bitmapHeight;
    float[] coordinates = new float[8];
    float[] vertices = new float[8];
    
    coordinates[0] = left;//left
    coordinates[1] = maxT;//top
    coordinates[2] = maxS;//right
    coordinates[3] = maxT;//top
    coordinates[4] = maxS;//right
    coordinates[5] = 0.0f;//bottom
    coordinates[6] = left;//left
    coordinates[7] = 0.0f;//bottom
    ByteBuffer byteBuf = ByteBuffer.allocateDirect(arraySize * floatSize);
    byteBuf.order(ByteOrder.nativeOrder());
    textureBuffer = byteBuf.asFloatBuffer();
    textureBuffer.put(coordinates);
    textureBuffer.position(0);
    
    final float leftX = -(float)width / 2;
    final float rightX = leftX + width;
    final float bottomY = -(float)height / 2;
    final float topY = bottomY + height;
    
    vertices[0] = leftX;
    vertices[1] = bottomY;
    vertices[2] = rightX;
    vertices[3] = bottomY;
    vertices[4] = rightX;
    vertices[5] = topY;
    vertices[6] = leftX;
    vertices[7] = topY;
    
    byteBuf = ByteBuffer.allocateDirect(arraySize * floatSize);
    byteBuf.order(ByteOrder.nativeOrder());
    vertexBuffer = byteBuf.asFloatBuffer();
    vertexBuffer.put(vertices);
    vertexBuffer.position(0);
*/
}

TESize TEUtilTexture::getBitmapSize() const {
    TESize size;
    size.width = mBitmapWidth;
    size.height = mBitmapHeight;
    return size;
}
	
TESize TEUtilTexture::getCropSize() const {
    TESize size;
    size.width = mCropWidth;
    size.height = mCropHeight;
    return size;
}
