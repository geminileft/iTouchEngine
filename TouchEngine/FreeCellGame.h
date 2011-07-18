//
//  FreeCellGame.h
//  TouchEngine
//
//  Created by geminileft on 7/16/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef FREECELLGAME

#define FREECELLGAME

#include "TEEngine.h"
#include "FreeCellGameObjectFactory.h"
#include "PlayingCard.h"

class FreeCellGame : public TEEngine {
public:
    FreeCellGame();
    virtual void start();
    void addTableStack(int startX, FreeCellGameObjectFactory* factory, PlayingCard* cards[][7]/*, TEComponent.EventListener listener*/);

private:
	FreeCellGameObjectFactory* mFactory;
};

#endif