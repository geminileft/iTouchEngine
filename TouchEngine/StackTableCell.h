//
//  StackTableCell.h
//  TouchEngine
//
//  Created by geminileft on 7/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef STACKTABLECELL
#define STACKTABLECELL

#include "TEComponentStack.h"

class StackTableCell : public TEComponentStack {

public:
    StackTableCell(StackType stackType);

    virtual void update();
	virtual int getStackOffset(bool isFirst);
	virtual bool doesAccept(TEComponentStack* stack);
	virtual void pushStack(TEComponentStack* stack);
	virtual void popStack(TEComponentStack* stack);

};
    
#endif