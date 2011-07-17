//
//  TEUtilTexture.cpp
//  TouchEngine
//
//  Created by geminileft on 7/16/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TEUtilTexture.h"

TEUtilTexture::TEUtilTexture(std::string resourceName, TEPoint position, TESize size) {
    glGenTextures(1, &mTextureName);
    //InputStream is = context.getResources().openRawResource(resourceId);
    glBindTexture(GL_TEXTURE_2D, mTextureName);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, size.width, size.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
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
