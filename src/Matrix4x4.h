//
// Created by Angel on 11/16/2020.
//

#ifndef CPP_MATH_MATRIX4X4_H
#define CPP_MATH_MATRIX4X4_H

#include "Vector4.h"

struct Matrix4x4 {

public:

    Matrix4x4() = default;

    Matrix4x4(float n00, float n01, float n02, float n03,
              float n10, float n11, float n12, float n13,
              float n20, float n21, float n22, float n23,
              float n30, float n31, float n32, float n33) {
        n[0][0] = n00;
        n[0][1] = n10;
        n[0][2] = n20;
        n[0][3] = n30;
        n[1][0] = n01;
        n[1][1] = n11;
        n[1][2] = n21;
        n[1][3] = n31;
        n[2][0] = n02;
        n[2][1] = n12;
        n[2][2] = n22;
        n[2][3] = n32;
        n[3][0] = n03;
        n[3][1] = n13;
        n[3][2] = n23;
        n[3][3] = n33;
    }

    Matrix4x4(const Vector4 &a, const Vector4 &b, const Vector4 &c, const Vector4 &d) {
        n[0][0] = a.x;
        n[0][1] = a.y;
        n[0][2] = a.z;
        n[0][3] = a.w;
        n[1][0] = b.x;
        n[1][1] = b.y;
        n[1][2] = b.z;
        n[1][3] = b.w;
        n[2][0] = c.x;
        n[2][1] = c.y;
        n[2][2] = c.z;
        n[2][3] = c.w;
        n[3][0] = d.x;
        n[3][1] = d.y;
        n[3][2] = d.z;
        n[3][3] = d.w;
    }

    float &operator()(int i, int j) {
        return (n[j][i]);
    }

    const float &operator()(int i, int j) const {
        return (n[j][i]);
    }

    Vector4 &operator[](int j) {
        return (*reinterpret_cast<Vector4 *>(n[j]));
    }

    const Vector4 &operator[](int j) const {
        return (*reinterpret_cast<const Vector4 *>(n[j]));
    }
    
protected:

    float n[4][4];
};


#endif //CPP_MATH_MATRIX4X4_H
