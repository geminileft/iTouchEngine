#ifndef TouchEngine_TEUtilMatrix_h
#define TouchEngine_TEUtilMatrix_h

enum MatrixStorageFormat {
    RowMajor
    , ColumnMajor
};

class TEUtilMatrix {
public:
    static void setFrustum(float* matrix, MatrixStorageFormat format, float left, float right, float bottom, float top, float near, float far);
    static void setIdentity(float* matrix);
    static void setTranslate(float* matrix, MatrixStorageFormat format, float x, float y, float z);
    static void setTranslateC(float* matrix, float x, float y, float z);
    static void setLookAt(float* matrix, float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ);
    static void transpose(float* matrix);
};

#endif
