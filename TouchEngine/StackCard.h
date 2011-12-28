#ifndef STACKCARD
#define STACKCARD

#include "TEComponentStack.h"

class PlayingCard;

class StackCard : public TEComponentStack {
private:
	bool mMoving;
	bool mMoveToFoundation;
	TEPoint mPreviousPosition;
	TEComponentStack* mPreviousStack;

public:
	StackCard(PlayingCard* card);

    virtual void update();
	virtual int getStackOffset(bool isFirst);
	virtual bool doesAccept(TEComponentStack* stack);
	
	void resetMoveToFoundation();
	bool isMoveToFoundation();
	
	void touchStartedListener();
	void touchEndedListener();
	void rejectMoveListener();
	void preMoveToFoundationListener();
};

#endif
