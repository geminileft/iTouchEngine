//
//  TEUtilTexture.cpp
//  TouchEngine
//
//  Created by geminileft on 7/16/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TEUtilTexture.h"
#include "TEUtilsMath.h"

TEUtilTexture::TEUtilTexture(NSString* resourceName, TEPoint position, TESize size) {
    glGenTextures(1, &mTextureName);
    UIImage* image = [UIImage imageNamed:resourceName];
    
    float bitmapHeight = image.size.height;
    float bitmapWidth = image.size.width;
    
    float width;
    float height;
    
    if (size.width != 0 || size.height != 0) {
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
    
    int textureHeight = closestPowerOf2(bitmapHeight);
    int textureWidth = closestPowerOf2(bitmapWidth);
    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
    if (bitmapHeight != textureHeight || bitmapWidth != textureWidth) {
        image = [image stretchableImageWithLeftCapWidth:textureWidth topCapHeight:textureHeight];
    }
    void *imageData = malloc( textureHeight * textureWidth * 4 );
    CGBitmapContextCreate(imageData
                         , width
                         , height
                         , 8
                         , 4 * width
                         , colorSpace
                         , kCGImageAlphaPremultipliedLast | kCGBitmapByteOrder32Big );
    glBindTexture(GL_TEXTURE_2D, mTextureName);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureWidth, textureHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
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
