//
//  TEUtilMatrix.cpp
//  TouchEngine
//
//  Created by developer on 11/9/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include "TEUtilMatrix.h"

void TEUtilMatrix::setFrustrum(float* matrix, float left, float right, float top, float bottom, float near, float far) {
    matrix[0] = (2 * near) / (right - left);
    matrix[1] = 0;
    matrix[2] = (right + left) / (right - left);
    matrix[3] = 0;
    
    matrix[4] = 0;
    matrix[5] = (2 * near) / (top - bottom);
    matrix[6] = (top + bottom) / (top - bottom);
    matrix[7] = 0;
    
    matrix[8] = 0;
    matrix[9] = 0;
    matrix[10] = - ((far + near) / (far - near));
    matrix[11] = - ((2 * far * near) / (far - near));
    
    matrix[12] = 0;
    matrix[13] = 0;
    matrix[14] = -1;
    matrix[15] = 0;    
}

void TEUtilMatrix::setIdentity(float* matrix) {
    matrix[0] = 1;
    matrix[1] = 0;
    matrix[2] = 0;
    matrix[3] = 0;
    
    matrix[4] = 0;
    matrix[5] = 1;
    matrix[6] = 0;
    matrix[7] = 0;
    
    matrix[8] = 0;
    matrix[9] = 0;
    matrix[10] = 1;
    matrix[11] = 0;
    
    matrix[12] = 0;
    matrix[13] = 0;
    matrix[14] = 0;
    matrix[15] = 1;
}

void TEUtilMatrix::setTranslate(float* matrix, float x, float y, float z) {
    matrix[0] = 1;
    matrix[1] = 0;
    matrix[2] = 0;
    matrix[3] = x;
    
    matrix[4] = 0;
    matrix[5] = 1;
    matrix[6] = 0;
    matrix[7] = y;
    
    matrix[8] = 0;
    matrix[9] = 0;
    matrix[10] = 1;
    matrix[11] = z;
    
    matrix[12] = 0;
    matrix[13] = 0;
    matrix[14] = 0;
    matrix[15] = 1;    
}

void TEUtilMatrix::setLookAt(float* matrix, float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ) {
    
}
