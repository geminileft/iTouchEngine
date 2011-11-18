#ifndef EAGLVIEW
#define EAGLVIEW

class TEEngine;

@interface EAGLView : UIView {
@private
	long mPreviousInterval;
    TEEngine* mGame;
}

- (id)initWithFrame:(CGRect)frame game:(TEEngine*) game;

@end

#endif