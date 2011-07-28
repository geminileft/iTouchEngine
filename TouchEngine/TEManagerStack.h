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

class TEManagerStack : public TEManagerComponent {

public:
    void update();
	static TEManagerStack* sharedManager();
	virtual void moveComponentToTop(TEComponent* component);
};


#endif
