//
// Created by Almoxis on 11/14/2020.
//

#ifndef CPP_MATH_SCALE_H
#define CPP_MATH_SCALE_H

#include "Matrix3x3.h"

inline Matrix3x3 MakeScale(float s) {
    return (Matrix3x3(
            s, 0.0f, 0.0f,
            0.0f, s, 0.0f,
            0.0f, 0.0f, s
    ));
}

inline Matrix3x3 MakeScale(float sx, float sy, float sz) {
    return (Matrix3x3(
            sx, 0.0f, 0.0f,
            0.0f, sy, 0.0f,
            0.0f, 0.0f, sz
    ));
}

inline Matrix3x3 MakeScale(float s, const Vector3 &a) {
    s -= 1.0f;
    float x = a.x * s;
    float y = a.y * s;
    float z = a.z * s;
    float axay = x * a.y;
    float axaz = x * a.z;
    float ayaz = y * a.z;

    return (Matrix3x3(
            x * a.x + 1.0f, axay, axaz,
            axay, y * a.y + 1.0f, ayaz,
            axaz, ayaz, z * a.z + 1.0f
    ));
}


#endif //CPP_MATH_SCALE_H
