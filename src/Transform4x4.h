//
// Created by Angel on 11/16/2020.
//

#ifndef CPP_MATH_TRANSFORM4X4_H
#define CPP_MATH_TRANSFORM4X4_H

#include "Vector3.h"
#include "Point3.h"
#include "Matrix4x4.h"

struct Transform4x4 : Matrix4x4 {
    Transform4x4() = default;

    Transform4x4(float n00, float n01, float n02, float n03,
                 float n10, float n11, float n12, float n13,
                 float n20, float n21, float n22, float n23) {
        n[0][0] = n00;
        n[0][1] = n10;
        n[0][2] = n20;
        n[1][0] = n01;
        n[1][1] = n11;
        n[1][2] = n21;
        n[2][0] = n02;
        n[2][1] = n12;
        n[2][2] = n22;
        n[3][0] = n03;
        n[3][1] = n13;
        n[3][2] = n23;

        n[0][3] = n[1][3] = n[2][3] = 0.0F;
        n[3][3] = 1.0F;
    }

    Transform4x4(const Vector3 &a, const Vector3 &b,
                 const Vector3 &c, const Point3 &p) {
        n[0][0] = a.x;
        n[0][1] = a.y;
        n[0][2] = a.z;
        n[1][0] = b.x;
        n[1][1] = b.y;
        n[1][2] = b.z;
        n[2][0] = c.x;
        n[2][1] = c.y;
        n[2][2] = c.z;
        n[3][0] = p.x;
        n[3][1] = p.y;
        n[3][2] = p.z;

        n[0][3] = n[1][3] = n[2][3] = 0.0F;
        n[3][3] = 1.0F;
    }

    Vector3 &operator[](int j) {
        return (*reinterpret_cast<Vector3 *>(n[j]));
    }

    const Vector3 &operator[](int j) const {
        return (*reinterpret_cast<const Vector3 *>(n[j]));
    }

    const Point3 &GetTranslation(void) const {
        return (*reinterpret_cast<const Point3 *>(n[3]));
    }

    void SetTranslation(const Point3 &p) {
        n[3][0] = p.x;
        n[3][1] = p.y;
        n[3][2] = p.z;
    }
};

Transform4x4 Inverse(const Transform4x4 &H) {
    const Vector3 &a = H[0];
    const Vector3 &b = H[1];
    const Vector3 &c = H[2];
    const Vector3 &d = H[3];

    Vector3 s = Vector3::Cross(a, b);
    Vector3 t = Vector3::Cross(c, d);

    float invDet = 1.0F / Vector3::Dot(s, c);

    s *= invDet;
    t *= invDet;
    Vector3 v = c * invDet;

    Vector3 r0 = Vector3::Cross(b, v);
    Vector3 r1 = Vector3::Cross(v, a);

    return (Transform4x4(r0.x, r0.y, r0.z, -Vector3::Dot(b, t),
                         r1.x, r1.y, r1.z, Vector3::Dot(a, t),
                         s.x, s.y, s.z, -Vector3::Dot(d, s)));
}

Transform4x4 operator*(const Transform4x4 &A, const Transform4x4 &B) {
    return (Transform4x4(
            A(0, 0) * B(0, 0) + A(0, 1) * B(1, 0) + A(0, 2) * B(2, 0),
            A(0, 0) * B(0, 1) + A(0, 1) * B(1, 1) + A(0, 2) * B(2, 1),
            A(0, 0) * B(0, 2) + A(0, 1) * B(1, 2) + A(0, 2) * B(2, 2),
            A(0, 0) * B(0, 3) + A(0, 1) * B(1, 3) + A(0, 2) * B(2, 3) + A(0, 3),
            A(1, 0) * B(0, 0) + A(1, 1) * B(1, 0) + A(1, 2) * B(2, 0),
            A(1, 0) * B(0, 1) + A(1, 1) * B(1, 1) + A(1, 2) * B(2, 1),
            A(1, 0) * B(0, 2) + A(1, 1) * B(1, 2) + A(1, 2) * B(2, 2),
            A(1, 0) * B(0, 3) + A(1, 1) * B(1, 3) + A(1, 2) * B(2, 3) + A(1, 3),
            A(2, 0) * B(0, 0) + A(2, 1) * B(1, 0) + A(2, 2) * B(2, 0),
            A(2, 0) * B(0, 1) + A(2, 1) * B(1, 1) + A(2, 2) * B(2, 1),
            A(2, 0) * B(0, 2) + A(2, 1) * B(1, 2) + A(2, 2) * B(2, 2),
            A(2, 0) * B(0, 3) + A(2, 1) * B(1, 3) + A(2, 2) * B(2, 3) + A(2, 3)));
}


#endif //CPP_MATH_TRANSFORM4X4_H
