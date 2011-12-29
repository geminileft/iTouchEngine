#ifndef TERUNNABLE_H
#define TERUNNABLE_H

class TEEngine;

@interface TERunnable : NSObject {
@private
    TEEngine* mGame;
}

-(id) initWithGame:(TEEngine*) game;
-(void) run;

@end

#endif