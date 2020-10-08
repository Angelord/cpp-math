//
// Created by Almoxis on 10/8/2020.
//

#ifndef CPP_MATH_UTILS_H
#define CPP_MATH_UTILS_H

#include <cmath>

struct Utils {

        static bool FloatEquals(float lhs, float rhs, float epsilon) {
            return std::fabs(lhs - rhs) < epsilon;
        }
};

#endif //CPP_MATH_UTILS_H
