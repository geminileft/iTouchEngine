#ifndef TEUTILTEXTURE
#define TEUTILTEXTURE

#include <string>
#include "TETypes.h"
#include <OpenGLES/ES1/glext.h>
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

class TEUtilTexture {
private:
	int mBitmapWidth;
	int mBitmapHeight;
	int mCropWidth;
	int mCropHeight;

public:
	GLuint mTextureName;
	TEUtilTexture(std::string resourceName, TEPoint position, TESize size);
    TESize getBitmapSize() const;
	TESize getCropSize() const;
};

#endif