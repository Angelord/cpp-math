//
// Created by Almoxis on 11/14/2020.
//

#ifndef CPP_MATH_SCALE_H
#define CPP_MATH_SCALE_H

#include "Matrix3x3.h"

inline Matrix3x3 MakeScaleUniform(float s) {
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

#endif //CPP_MATH_SCALE_H
