//
//  FreeCellGame.h
//  TouchEngine
//
//  Created by geminileft on 7/16/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef FREECELLGAME
#define FREECELLGAME

#define START_X 28
#define X_GAP 2

#include "TEEngine.h"
#include "FreeCellGameObjectFactory.h"
#include "PlayingCard.h"

class FreeCellGame : public TEEngine {
private:
	FreeCellGameObjectFactory* mFactory;

public:
    FreeCellGame(int width, int height);	
    virtual void start();
    void addTableStack(int startX, FreeCellGameObjectFactory* factory, PlayingCard* cards[][7], TEEventListenerBase* listener);
	TEEventListenerBase* addHUDMoves();
};

#endif