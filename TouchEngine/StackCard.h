//
//  StackCard.h
//  TouchEngine
//
//  Created by geminileft on 7/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef STACKCARD
#define STACKCARD

#include "TEComponentStack.h"

class PlayingCard;

class StackCard : public TEComponentStack {
public:
	StackCard(PlayingCard* card);

    virtual void update();
	virtual int getStackOffset(bool isFirst);
};

#endif
