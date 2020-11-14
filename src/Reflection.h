//
// Created by Almoxis on 11/14/2020.
//

#ifndef CPP_MATH_REFLECTION_H
#define CPP_MATH_REFLECTION_H

#include "Matrix3x3.h"
#include "Vector3.h"

// a is the vector perpendicular to the plane we are reflecting through
inline Matrix3x3 MakeReflection(const Vector3 &a) {
    float x = a.x * -2.0f;
    float y = a.y * -2.0f;
    float z = a.z * -2.0f;
    float axay = x * a.y;
    float axaz = x * a.z;
    float ayaz = y * a.z;

    return (
            Matrix3x3(x * a.x + 1.0f, axay, axaz,
                      axay, y * a.y + 1.0f, ayaz,
                      axaz, ayaz, z * a.z + 1.0f)
    );
}

inline Matrix3x3 MakeConvolution(const Vector3 &a) {
    float x = a.x * 2.0f;
    float y = a.y * 2.0f;
    float z = a.z * 2.0f;
    float axay = x * a.y;
    float axaz = x * a.z;
    float ayaz = y * a.z;

    return (Matrix3x3(
            x * a.x - 1.0f, axay, axaz,
            axay, y * a.y - 1.0f, ayaz,
            axaz, ayaz, z * a.z - 1.0f)
    );
}

#endif //CPP_MATH_REFLECTION_H
