#ifndef STACKACECELL
#define STACKACECELL

#include "TEComponentStack.h"

class StackAceCell : public TEComponentStack {
public:
	StackAceCell();

	virtual int getStackOffset(bool isFirst);
	virtual bool doesAccept(TEComponentStack* stack);
	virtual void update();
};

#endif