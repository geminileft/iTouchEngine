#import <UIKit/UIKit.h>
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

@class EAGLContext;

@interface EAGLView : UIView {
@private
    GLint framebufferWidth;
    GLint framebufferHeight;
    GLuint defaultFramebuffer;
    GLuint colorRenderbuffer;
}

@property (nonatomic, retain) EAGLContext *context;

- (void)setFramebuffer;
- (BOOL)presentFramebuffer;
- (void)deleteFramebuffer;
- (void)startAnimation;

@end
