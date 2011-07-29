//
//  TEComponentStack.h
//  TouchEngine
//
//  Created by geminileft on 7/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef TECOMPONENTSTACK
#define TECOMPONENTSTACK

#include "TEComponent.h"

#define CARD_OFFSET 40

class PlayingCard;

enum StackType {
    FreeCell
    , AceCell
    , TableCell
    , Card
};

typedef enum StackType StackType;

class TEComponentStack : public TEComponent {
private:
	StackType mStackType;
	PlayingCard* mCard;
	TEComponentStack* mChildStack;
	TEComponentStack* mParentStack;
	bool mTopStack;	

public:
	bool isEvaluateReady;

	TEComponentStack(StackType stackType);
	virtual int getStackOffset(bool isFirst) = 0;
	bool doesAccept(TEComponentStack* stack);
    void setPlayingCard(PlayingCard* card);
	PlayingCard* getPlayingCard();
	void pushStack(TEComponentStack* stack);
    void setParentStack(TEComponentStack* stack);
    void adjustStackPositions();
    TEComponentStack* getRootStack();
	TEComponentStack* getParentStack();
    TEComponentStack* getChildStack();
	static int getOpenTableCellCount();
	static int getOpenFreeCellCount();
	int getPickupCount(int freeCellCount, int tableCellCount);
	void popStack(TEComponentStack* stack);
};

#endif
