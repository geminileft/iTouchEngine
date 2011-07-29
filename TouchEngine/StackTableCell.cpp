//
//  StackTableCell.cpp
//  TouchEngine
//
//  Created by geminileft on 7/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "StackTableCell.h"
#include "PlayingCard.h"

StackTableCell::StackTableCell(StackType stackType) : TEComponentStack(stackType) {}

int StackTableCell::getStackOffset(bool isFirst) {
    int offset = 0;
    if (isFirst) {
        offset = 0;
    } else {
        offset = CARD_OFFSET;
    }
    return offset;
}

void StackTableCell::update() {}

bool StackTableCell::doesAccept(TEComponentStack* stack) {
	bool results = false;
	TEComponentStack* childStack = getChildStack();
	
	if (childStack == NULL) {
		const int dropCount = getPickupCount(getOpenFreeCellCount(), getOpenTableCellCount() - 1);
		childStack = stack;
		int stackCount = 0;
		while (childStack != NULL) {
			++stackCount;
			childStack = childStack->getChildStack();
		}
		results = stackCount <= dropCount;
	} else {
		while (childStack->getChildStack() != NULL) {
			childStack = childStack->getChildStack();
		}
		PlayingCard* card = childStack->getPlayingCard();
		PlayingCard* stackCard = stack->getPlayingCard();
		results = card->canStack(stackCard);	
	}
	return results;
}

/*
    
	@Override
	public void pushStack(TEComponentStack stack) {
		super.pushStack(stack);
		--TEComponentStack.openTableCellCount;
	}
	
	@Override
	public void popStack(TEComponentStack stack) {
		super.popStack(stack);
		++TEComponentStack.openTableCellCount;
	}
    
}
*/