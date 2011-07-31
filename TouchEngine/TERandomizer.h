//
//  TERandomizer.h
//  TouchEngine
//
//  Created by geminileft on 7/31/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef TERANDOMIZER
#define TERANDOMIZER

class TERandomizer {
private:
	unsigned int mNumber;

public:
	TERandomizer(unsigned int seed);
	unsigned int next();
};
#endif