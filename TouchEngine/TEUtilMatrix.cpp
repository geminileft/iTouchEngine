//
//  TEUtilMatrix.cpp
//  TouchEngine
//
//  Created by developer on 11/9/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include "TEUtilMatrix.h"

void TEUtilMatrix::setFrustum(float* matrix, float left, float right, float bottom, float top, float near, float far) {
    matrix[0] = (2.0f * near) / (right - left);
    matrix[1] = 0;
    matrix[2] = (right + left) / (right - left);
    matrix[3] = 0;
    
    matrix[4] = 0;
    matrix[5] = (2.0f * near) / (top - bottom);
    matrix[6] = (top + bottom) / (top - bottom);
    matrix[7] = 0;
    
    matrix[8] = 0;
    matrix[9] = 0;
    matrix[10] = - ((far + near) / (far - near));
    matrix[11] = - ((2.0f * far * near) / (far - near));
    
    matrix[12] = 0;
    matrix[13] = 0;
    matrix[14] = -1.0f;
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

void TEUtilMatrix::setTranslateC(float* matrix, float x, float y, float z) {
    setTranslate(matrix, x, y, z);
    transpose(matrix);
}

void TEUtilMatrix::setLookAt(float* matrix, float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ) {
    
}

void TEUtilMatrix::transpose(float* matrix) {
    float transpose[16];
    transpose[0] = matrix[0];
    transpose[1] = matrix[4];
    transpose[2] = matrix[8];
    transpose[3] = matrix[12];
    
    transpose[4] = matrix[1];
    transpose[5] = matrix[5];
    transpose[6] = matrix[9];
    transpose[7] = matrix[13];
    
    transpose[8] = matrix[2];
    transpose[9] = matrix[6];
    transpose[10] = matrix[10];
    transpose[11] = matrix[14];
    
    transpose[12] = matrix[3];
    transpose[13] = matrix[7];
    transpose[14] = matrix[11];
    transpose[15] = matrix[15];
    
    matrix[0] = transpose[0];
    matrix[1] = transpose[1];
    matrix[2] = transpose[2];
    matrix[3] = transpose[3];
    
    matrix[4] = transpose[4];
    matrix[5] = transpose[5];
    matrix[6] = transpose[6];
    matrix[7] = transpose[7];
    
    matrix[8] = transpose[8];
    matrix[9] = transpose[9];
    matrix[10] = transpose[10];
    matrix[11] = transpose[11];
    
    matrix[12] = transpose[12];
    matrix[13] = transpose[13];
    matrix[14] = transpose[14];
    matrix[15] = transpose[15];
    
}

