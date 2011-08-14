//
//  RenderMenu.h
//  TouchEngine
//
//  Created by geminileft on 8/7/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef RENDERMENU
#define RENDERMENU

#include "TEComponentRender.h"
#include "TETypes.h"

class TEUtilTexture;

class RenderMenu : public TEComponentRender {
private:
	TEUtilTexture* mTexture;
	
	int mCrop[4];
	TESize mSize;
	TEPoint mPosition;
	
public:
    RenderMenu(NSString* menuResourceName, NSString* buttonResourceName, TEPoint menuPosition, TEPoint buttonPosition);

    virtual void update();
    virtual void draw();
};
#endif

