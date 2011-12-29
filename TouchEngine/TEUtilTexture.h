#ifndef TEUTILTEXTURE
#define TEUTILTEXTURE

#include "TETypes.h"
#include <string>
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

class TEUtilTexture {
private:
	float mBitmapWidth;
	float mBitmapHeight;
	int mCropWidth;
	int mCropHeight;
    
public:
	uint mTextureName;
	float mTextureBuffer[8];
	float mVertexBuffer[8];
	TEUtilTexture(NSString* resourceName, TEPoint position, TESize size);
    TESize getBitmapSize() const;
	TESize getCropSize() const;
};

#endif