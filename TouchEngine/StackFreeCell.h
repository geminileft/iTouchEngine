#ifndef STACKFREECELL
#define STACKFREECELL

#include "TEComponentStack.h"

class StackFreeCell : public TEComponentStack {
public:
	StackFreeCell();
	virtual int getStackOffset(bool isFirst);
	virtual bool doesAccept(TEComponentStack* stack);
	virtual void update();
	virtual void pushStack(TEComponentStack* stack);
	virtual void popStack(TEComponentStack* stack);
};

#endif
