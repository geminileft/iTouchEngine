#import "EAGLView.h"
#import <QuartzCore/QuartzCore.h>

#include "TEInputTouch.h"
#include "TEManagerInput.h"

@implementation EAGLView

+ (Class)layerClass {
    return [CAEAGLLayer class];
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
    TEManagerInput* inputManager = TEManagerInput::sharedManager();
    CGRect screenSize = [[UIScreen mainScreen] bounds];
    for (UITouch* touch in touches) {
        CGPoint point = [touch locationInView:self];
        float x = point.x;
        float y = screenSize.size.height - point.y;
        TEInputTouch* inputTouch = new TEInputTouch([touch hash], x, y);
        inputManager->beginTouch(inputTouch);
    }
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event {
    TEManagerInput* inputManager = TEManagerInput::sharedManager();
    CGRect screenSize = [[UIScreen mainScreen] bounds];
    for (UITouch* touch in touches) {
        CGPoint point = [touch locationInView:self];
        float x = point.x;
        float y = screenSize.size.height - point.y;	
        TEInputTouch* inputTouch = new TEInputTouch([touch hash], x, y);
        inputManager->moveTouch(inputTouch);
    }
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
    TEManagerInput* inputManager = TEManagerInput::sharedManager();
    CGRect screenSize = [[UIScreen mainScreen] bounds];
    for (UITouch* touch in touches) {
        CGPoint point = [touch locationInView:self];
        float x = point.x;
        float y = screenSize.size.height - point.y;	
        TEInputTouch* inputTouch = new TEInputTouch([touch hash], x, y);
        inputManager->endTouch(inputTouch);
    }
}

- (void)dealloc
{
    [super dealloc];
}

@end
