//
//  TERandomizer.cpp
//  TouchEngine
//
//  Created by geminileft on 7/31/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TERandomizer.h"

TERandomizer::TERandomizer(unsigned int seed) : mNumber(seed){}

unsigned int TERandomizer::next() {
	mNumber ^= (mNumber << 13);
	mNumber ^= (mNumber >> 17);
	mNumber ^= (mNumber << 5);
	return mNumber;

}