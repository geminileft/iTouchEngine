//
//  TEUtilTexture.cpp
//  TouchEngine
//
//  Created by geminileft on 7/16/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TEUtilTexture.h"
#include "TEUtilsMath.h"

typedef enum {
	kTexture2DPixelFormat_Automatic = 0,
	kTexture2DPixelFormat_RGBA8888,
	kTexture2DPixelFormat_RGB565,
	kTexture2DPixelFormat_A8,
} Texture2DPixelFormat;

TEUtilTexture::TEUtilTexture(NSString* resourceName, TEPoint position, TESize size) :
	mBitmapWidth(0), mBitmapHeight(0) {
    UIImage* image = [UIImage imageNamed:resourceName];

	float left;
	if (position.x != 0 || position.y != 0) {
		left = position.x / size.width;
	} else {
		left = 0;
	}
	float width;
	float height;
	if (size.height != 0 || size.width != 0) {
		width = size.width;
		height = size.height;
	} else {
		width = image.size.width;
		height = image.size.height;
	}
	
	const float maxS = ((float)width / image.size.width) + left;
	const float maxT = (float)height / image.size.height;
	
	mTextureBuffer[0] = left;//left
	mTextureBuffer[1] = maxT;//top
	mTextureBuffer[2] = maxS;//right
	mTextureBuffer[3] = maxT;//top
	mTextureBuffer[4] = maxS;//right
	mTextureBuffer[5] = 0.0f;//bottom
	mTextureBuffer[6] = left;//left
	mTextureBuffer[7] = 0.0f;//bottom

	const float leftX = -(float)width / 2;
	const float rightX = leftX + width;
	const float bottomY = -(float)height / 2;
	const float topY = bottomY + height;
	
	mVertexBuffer[0] = leftX;
	mVertexBuffer[1] = bottomY;
	mVertexBuffer[2] = rightX;
	mVertexBuffer[3] = bottomY;
	mVertexBuffer[4] = rightX;
	mVertexBuffer[5] = topY;
	mVertexBuffer[6] = leftX;
	mVertexBuffer[7] = topY;

    CGImage* cImage = [image CGImage];
    mBitmapWidth = CGImageGetWidth(cImage);
    mBitmapHeight = CGImageGetHeight(cImage);
    mTextureName = GLUtexImage2D(cImage);
}

TESize TEUtilTexture::getBitmapSize() const {
	/**********************
	 HACKATHON!!! WTF!!
	 *********************/
    TESize size3;
	TESize size2;
	size3.width = mBitmapWidth;
	size3.height = mBitmapHeight;
	size2.width = 15;
	size2.height = 30;
    return size3;
}

TESize TEUtilTexture::getCropSize() const {
    TESize size;
    size.width = mCropWidth;
    size.height = mCropHeight;
    return size;
}

uint TEUtilTexture::GLUtexImage2D(CGImageRef cgImage) const {
    NSUInteger width;
    NSUInteger height;
    float i;
    CGContextRef			context = nil;
    void*					data = nil;;
    CGColorSpaceRef			colorSpace;
    void*					tempData;
    unsigned int*			inPixel32;
    unsigned short*			outPixel16;
    BOOL					hasAlpha;
    CGImageAlphaInfo		info;
    Texture2DPixelFormat    pixelFormat;
    
    
    info = CGImageGetAlphaInfo(cgImage);
    hasAlpha = ((info == kCGImageAlphaPremultipliedLast)
                || (info == kCGImageAlphaPremultipliedFirst)
                || (info == kCGImageAlphaLast)
                || (info == kCGImageAlphaFirst));
    
    if(CGImageGetColorSpace(cgImage)) {
        if(hasAlpha)
            pixelFormat = kTexture2DPixelFormat_RGBA8888;
        else
			pixelFormat = kTexture2DPixelFormat_RGB565;
    } else  //NOTE: No colorspace means a mask image
        pixelFormat = kTexture2DPixelFormat_A8;
    
    width = CGImageGetWidth(cgImage);
    height = CGImageGetHeight(cgImage);
    width = closestPowerOf2(mBitmapWidth);
    height = closestPowerOf2(mBitmapHeight);
    
    switch(pixelFormat) {
        case kTexture2DPixelFormat_RGBA8888:
            colorSpace = CGColorSpaceCreateDeviceRGB();
            data = malloc(height * width * 4);
            context = CGBitmapContextCreate(data, width, height, 8, 4 * width, colorSpace,
											kCGImageAlphaPremultipliedLast | kCGBitmapByteOrder32Big);
            CGColorSpaceRelease(colorSpace);
            break;
        case kTexture2DPixelFormat_RGB565:
            colorSpace = CGColorSpaceCreateDeviceRGB();
            data = malloc(height * width * 4);
            context = CGBitmapContextCreate(data, width, height, 8, 4 * width, colorSpace,
											kCGImageAlphaNoneSkipLast | kCGBitmapByteOrder32Big);
            CGColorSpaceRelease(colorSpace);
            break;
            
        case kTexture2DPixelFormat_A8:
            data = malloc(height * width);
            context = CGBitmapContextCreate(data, width, height, 8, width, NULL, kCGImageAlphaOnly);
            break;				
        default:
            [NSException raise:NSInternalInconsistencyException format:@"Invalid pixel format"];
    }
    
	CGContextClearRect(context, CGRectMake(0, 0, width, height));
    CGContextDrawImage(context, CGRectMake(0, 0, CGImageGetWidth(cgImage), CGImageGetHeight(cgImage)), cgImage);
    if(pixelFormat == kTexture2DPixelFormat_RGB565) {
        tempData = malloc(height * width * 2);
        inPixel32 = (unsigned int*)data;
        outPixel16 = (unsigned short*)tempData;
        for(i = 0; i < width * height; ++i, ++inPixel32)
            *outPixel16++ = ((((*inPixel32 >> 0) & 0xFF) >> 3) << 11) | ((((*inPixel32 >> 8) & 0xFF) >> 2) << 5) | ((((*inPixel32 >> 16) & 0xFF) >> 3) << 0);
        free(data);
        data = tempData;
        
    }
	
    uint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);    
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    switch(pixelFormat) {
            
        case kTexture2DPixelFormat_RGBA8888:
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            break;
        case kTexture2DPixelFormat_RGB565:
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, data);
            break;
        case kTexture2DPixelFormat_A8:
            glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, width, height, 0, GL_ALPHA, GL_UNSIGNED_BYTE, data);
            break;
        default:
            [NSException raise:NSInternalInconsistencyException format:@""];
    }
	free(data);
    return texture;
}
