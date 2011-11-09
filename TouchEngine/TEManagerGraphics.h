//
//  TEManagerGraphics.h
//  TouchEngine
//
//  Created by developer on 11/7/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef TouchEngine_TEManagerGraphics_h
#define TouchEngine_TEManagerGraphics_h

#import <QuartzCore/QuartzCore.h>

class TEManagerGraphics {
public:
    static void initialize(CALayer* layer);
    static void render();
};

#endif
