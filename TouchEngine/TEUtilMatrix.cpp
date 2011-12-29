#include "TEUtilMatrix.h"

/*
 row major | column major

 row[0] = column[0];
 row[1] = column[4];
 row[2] = column[8];
 row[3] = column[12];
 
 row[4] = column[1];
 row[5] = column[5];
 row[6] = column[9];
 row[7] = column[13];
 
 row[8] = column[2];
 row[9] = column[6];
 row[10] = column[10];
 row[11] = column[14];
 
 row[12] = column[3];
 row[13] = column[7];
 row[14] = column[11];
 row[15] = column[15];

*/

void TEUtilMatrix::setFrustum(float* matrix, MatrixStorageFormat format, float left, float right, float bottom, float top, float near, float far) {
    matrix[0] = (2.0f * near) / (right - left);
    matrix[4] = 0;
    matrix[8] = (right + left) / (right - left);
    matrix[12] = 0;
    
    matrix[1] = 0;
    matrix[5] = (2.0f * near) / (top - bottom);
    matrix[9] = (top + bottom) / (top - bottom);
    matrix[13] = 0;
    
    matrix[2] = 0;
    matrix[6] = 0;
    matrix[10] = - ((far + near) / (far - near));
    matrix[14] = - ((2.0f * far * near) / (far - near));
    
    matrix[3] = 0;
    matrix[7] = 0;
    matrix[11] = -1.0f;
    matrix[15] = 0;
    
    if (format == RowMajor)
        transpose(matrix);
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

void TEUtilMatrix::setTranslate(float* matrix, MatrixStorageFormat format, float x, float y, float z) {
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
    
    if (format == ColumnMajor)
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

