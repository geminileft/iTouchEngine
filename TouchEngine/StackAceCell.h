//
//  StackAceCell.h
//  TouchEngine
//
//  Created by geminileft on 7/29/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

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