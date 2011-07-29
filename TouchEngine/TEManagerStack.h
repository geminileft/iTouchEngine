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

class TEComponentStack;
class TEEventListenerBase;
class StackAceCell;

class TEManagerStack : public TEManagerComponent {
private:
	StackAceCell* mAceStacks[ACE_STACK_COUNT];

public:
    void update();
	static TEManagerStack* sharedManager();
	virtual void moveComponentToTop(TEComponent* component);
	TEComponentStack* getDropStack(TEComponentStack* component);
	void addAceStack(StackAceCell* aceStack);
};


#endif
