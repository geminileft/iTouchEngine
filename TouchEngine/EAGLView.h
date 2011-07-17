#import <UIKit/UIKit.h>
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

#include "TEEngine.h"

@class EAGLContext;

@interface EAGLView : UIView {
@private
    GLint framebufferWidth;
    GLint framebufferHeight;
    GLuint defaultFramebuffer;
    GLuint colorRenderbuffer;
    TEEngine* mGame;
    
}

@property (nonatomic, retain) EAGLContext *context;

- (id)initWithFrame:(CGRect)frame game:(TEEngine*) game;
- (void)startAnimation;

@end
