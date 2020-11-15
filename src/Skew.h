//
// Created by Almoxis on 11/15/2020.
//

#ifndef CPP_MATH_SKEW_H
#define CPP_MATH_SKEW_H

#include "Matrix3x3.h"

inline Matrix3x3 MakeSkew(float t, const Vector3 &a, const Vector3 &b) {

    t = tan(t);
    float x = a.x * t;
    float y = a.y * t;
    float z = a.z * t;

    return (Matrix3x3(x * b.x + 1.0f, x * b.y, x * b.z,
                      y * b.x, y * b.y + 1.0f, y * b.z,
                      z * b.x, z * b.y, z * b.z + 1.0f
    ));
}

#endif //CPP_MATH_SKEW_H
