//
// Created by Almoxis on 4/21/2020.
//

#ifndef CPP_MATH_MATRIX3X3_H
#define CPP_MATH_MATRIX3X3_H

#include "Vector3.h"

struct Matrix3x3 {

    public:

        Matrix3x3() = default;

        Matrix3x3(float n00, float n01, float n02,
                  float n10, float n11, float n12,
                  float n20, float n21, float n22) {
            n[0][0] = n00; n[0][1] = n01; n[0][2] = n02;
            n[1][0] = n10; n[1][1] = n11; n[1][2] = n12;
            n[2][0] = n20; n[2][1] = n21; n[2][2] = n22;
        }

        Matrix3x3(const Vector3& a, const Vector3& b, const Vector3& c) {
            n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z;
            n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z;
            n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z;
        }

        float& operator ()(size_t i, size_t j) {
            return (n[i][j]);
        }

        const float& operator ()(size_t i, size_t j) const {
            return (n[i][j]);
        }

        Vector3& operator [](int j) {
            return (*reinterpret_cast<Vector3 *>(n[j]));
        }

        const Vector3&operator [](int j) const {
            return (*reinterpret_cast<const Vector3 *>(n[j]));
        }

    private:

        float n[3][3];
};

#endif //CPP_MATH_MATRIX3X3_H
