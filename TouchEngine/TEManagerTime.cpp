//
//  TEManagerTime.cpp
//  TouchEngine
//
//  Created by geminileft on 7/31/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TEManagerTime.h"
#import <QuartzCore/QuartzCore.h>

long TEManagerTime::currentTime() {
	return 1000 * CACurrentMediaTime();
	//double difference = currentTime - mPreviousInterval;
	//NSLog(@"frame: %.3f", difference);
	//mPreviousInterval = currentTime;
}