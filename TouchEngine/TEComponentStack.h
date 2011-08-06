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

#define CARD_OFFSET 30

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
	bool mIsEvaluateReady;
	
	TEComponentStack(StackType stackType);
	
	virtual int getStackOffset(bool isFirst) = 0;
	virtual bool doesAccept(TEComponentStack* stack) = 0;
	virtual void pushStack(TEComponentStack* stack);
	virtual void popStack(TEComponentStack* stack);
	
	static int getOpenTableCellCount();
	static int getOpenFreeCellCount();
	static void setOpenTableCellCount(int openTableCellCount);
	static void setOpenFreeCellCount(int openFreeCellCount);
	
    void setPlayingCard(PlayingCard* card);
	PlayingCard* getPlayingCard();
    void setParentStack(TEComponentStack* stack);
    void adjustStackPositions();
    TEComponentStack* getRootStack();
	TEComponentStack* getParentStack();
    TEComponentStack* getChildStack();
	int getPickupCount(int freeCellCount, int tableCellCount);
	void evaluate();
	void resetEvaluate();
	bool isTopStack();
	bool doesOverlap(TEComponentStack* stack);
	bool isParentOf(TEComponentStack* stack);
};

#endif
