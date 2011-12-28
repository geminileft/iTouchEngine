#include "StackTableCell.h"
#include "PlayingCard.h"

StackTableCell::StackTableCell(StackType stackType) : TEComponentStack(stackType), mClear(false) {}

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

void StackTableCell::pushStack(TEComponentStack* stack) {
	TEComponentStack::pushStack(stack);
	TEComponentStack::setOpenTableCellCount(TEComponentStack::getOpenTableCellCount() - 1);
}
	
void StackTableCell::popStack(TEComponentStack* stack) {
	TEComponentStack::popStack(stack);
	TEComponentStack::setOpenTableCellCount(TEComponentStack::getOpenTableCellCount() + 1);
}

void StackTableCell::setClear() {
	mClear = true;
}

bool StackTableCell::getClear() const {
	return mClear;
}

