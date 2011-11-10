//
//  TEUtilMatrix.h
//  TouchEngine
//
//  Created by developer on 11/9/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef TouchEngine_TEUtilMatrix_h
#define TouchEngine_TEUtilMatrix_h

class TEUtilMatrix {
public:
    static void setFrustrum(float* matrix, float left, float right, float top, float bottom, float near, float far);
    static void setIdentity(float* matrix);
    static void setTranslate(float* matrix, float x, float y, float z);
    static void setLookAt(float* matrix, float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ);
};

#endif
