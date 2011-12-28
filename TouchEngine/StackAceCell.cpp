#include "StackAceCell.h"
#include "PlayingCard.h"

StackAceCell::StackAceCell() : TEComponentStack(AceCell) {
}
	
int StackAceCell::getStackOffset(bool isFirst) {
	return 0;
}
	
bool StackAceCell::doesAccept(TEComponentStack* stack) {
	bool accept = false;
	if (stack->getChildStack() == NULL) {
		PlayingCard* card = stack->getPlayingCard();
		TEComponentStack* childStack = getChildStack();
		if (childStack == NULL) {
			accept = (card->getFaceValue() == Ace);
		} else {
			PlayingCard* childCard = childStack->getPlayingCard();
			if (card->getSuit() == childCard->getSuit()) {
				while (childStack->getChildStack() != NULL) {
					childStack = childStack->getChildStack();
				}
				childCard = childStack->getPlayingCard();
				accept = ((childCard->getFaceValue() + 1) == card->getFaceValue());
			}
		}
	}
	return accept;
}
	
void StackAceCell::update() {}
