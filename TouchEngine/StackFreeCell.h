//
//  StackFreeCell.h
//  TouchEngine
//
//  Created by geminileft on 7/29/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

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
