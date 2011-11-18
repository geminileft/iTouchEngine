//
//  TEUtilsMath.h
//  TouchEngine
//
//  Created by geminileft on 7/17/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef TEUTILSMATH
#define TEUTILSMATH

#define MAX_TEXTURE_SIZE 1024

inline int closestPowerOf2(int n) {
    int c = 1;
    while (c < n && c < MAX_TEXTURE_SIZE)
        c <<= 1;
    return c;
}

#endif