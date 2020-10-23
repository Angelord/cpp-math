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

#endif //CPP_MATH_ROTATION_H
