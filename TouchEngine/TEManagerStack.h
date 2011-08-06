//
//  TEManagerStack.h
//  TouchEngine
//
//  Created by geminileft on 7/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef TEMANAGERSTACK
#define TEMANAGERSTACK

#include "TEManagerComponent.h"

#define ACE_STACK_COUNT 4
#define TABLE_STACK_COUNT 8

class TEComponentStack;
class TEEventListenerBase;
class StackAceCell;
class StackTableCell;

class TEManagerStack : public TEManagerComponent {
private:
	StackAceCell* mAceStacks[ACE_STACK_COUNT];
	StackTableCell* mTableStacks[TABLE_STACK_COUNT];

public:
	virtual void moveComponentToTop(TEComponent* component);
    virtual void update();
	
	static TEManagerStack* sharedManager();
	
	TEComponentStack* getDropStack(TEComponentStack* component);
	void addAceStack(StackAceCell* aceStack);
	void addTableStack(StackTableCell* tableStack);
	void moveToAceStack();
	void touchAcceptListener();
	TEEventListenerBase* getMoveToAceStackListener();
	TEEventListenerBase* getTouchAcceptListener();
};


#endif
