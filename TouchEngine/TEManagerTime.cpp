#include "TEManagerTime.h"

#import <QuartzCore/QuartzCore.h>

long TEManagerTime::currentTime() {
	return 1000 * CACurrentMediaTime();
}