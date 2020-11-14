//
// Created by Almoxis on 10/23/2020.
//

#ifndef CPP_MATH_ROTATION_H
#define CPP_MATH_ROTATION_H

#include "Matrix3x3.h"

inline Matrix3x3 MakeRotationX(float t) {

    float c = cos(t);
    float s = sin(t);

    return (Matrix3x3(
            1.0f, 0.0f, 0.0f,
            0.0f, c, -s,
            0.0f, s, c
            ));
}

inline Matrix3x3 MakeRotationY(float t) {

    float c = cos(t);
    float s = sin(t);

    return (Matrix3x3(
            c, 0.0f, s,
            0.0f, 1.0f, 0.0f,
            -s, 0.0f, c
            ));
}

inline Matrix3x3 MakeRotationZ(float t) {

    float c = cos(t);
    float s = sin(t);

    return (Matrix3x3(
            c, -s, 0.0f,
            s, c, 0.0f,
            0.0f, 0.0f, 1.0f
            ));
}

inline Matrix3x3 MakeRotation(float t, const Vector3& a) {
    float c = cos(t);
    float s = sin(t);
    float d = 1.0f - c;

    float x = a.x * d;
    float y = a.y * d;
    float z = a.z * d;

    float axay = x * a.y;
    float axaz = x * a.z;
    float ayaz = y * a.z;

    return (
            Matrix3x3(c + x * a.x, axay - s * a.z, axaz + s * a.y,
                    axay + s * a.z, c + y * a.y, ayaz - s * a.x,
                    axaz - s * a.y, ayaz + s * a.x, c + z * a.z)
            );
}

#endif //CPP_MATH_ROTATION_H
