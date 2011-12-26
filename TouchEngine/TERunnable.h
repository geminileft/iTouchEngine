//
//  TERunnable.h
//  TouchEngine
//
//  Created by dev on 12/26/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

class TEEngine;

@interface TERunnable : NSObject {
@private
    TEEngine* mGame;
}

-(id) initWithGame:(TEEngine*) game;
-(void) run;

@end
