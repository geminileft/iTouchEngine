//
//  StackTableCell.cpp
//  TouchEngine
//
//  Created by geminileft on 7/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "StackTableCell.h"

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

StackTableCell::StackTableCell(StackType stackType) {
    //TEComponentStack(stackType);
    // TODO Auto-generated constructor stub
}

/*
    
	@Override
	public boolean doesAccept(TEComponentStack stack) {
		boolean results = false;
		TEComponentStack childStack = getChildStack();
		
		if (childStack == null) {
			final int dropCount = getPickupCount(openFreeCellCount, openTableCellCount - 1);
			childStack = stack;
			int stackCount = 0;
			while (childStack != null) {
				++stackCount;
				childStack = childStack.getChildStack();
			}
			results = stackCount <= dropCount;
		} else {
			while (childStack.getChildStack() != null) {
				childStack = childStack.getChildStack();
			}
			PlayingCard card = childStack.getPlayingCard();
			PlayingCard stackCard = stack.getPlayingCard();
			results = card.canStack(stackCard);	
		}
		return results;
	}
    
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