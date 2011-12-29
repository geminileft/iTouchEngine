#ifndef TouchEngine_TEManagerTexture_h
#define TouchEngine_TEManagerTexture_h

#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#import <QuartzCore/QuartzCore.h>

class TEManagerTexture {
private:
    static int closestPowerOf2(int n);
    
public:
    static uint GLUtexImage2D(CGImageRef cgImage);
    
};

#endif
