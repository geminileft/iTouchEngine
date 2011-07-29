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
private:
	bool mMoving;
	TEPoint mPreviousPosition;
	TEComponentStack* mPreviousStack;

public:
	StackCard(PlayingCard* card);

    virtual void update();
	virtual int getStackOffset(bool isFirst);
	void moveToTopListener();
	void touchEndedListener();
	virtual bool doesAccept(TEComponentStack* stack);
};

#endif
