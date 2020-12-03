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

// Multiplies a Vec3 representing a normal vector as a row matrix on the right by a transform4x4 structure to
// transform a normal vector from one coordinate system to another.
// Note that this transform would transform a 'regular' vector form coordinate system A to B,
// whilst a normal vector is transformed from B to A
inline Vector3 operator *(const Vector3& n, const Transform4x4& h) {

    return (Vector3(n.x * h(0, 0) + n.y * h(1, 0) + n.z * h(2, 0),
                    n.x * h(0, 1) + n.y * h(1, 1) + n.z * h(2, 1),
                    n.x * h(0, 2) + n.y * h(1, 2) + n.z * h(2, 2)));
}

// Multiplies a plane on the right by a Transform4x4 to transform the plane from coordinate system B
// to coordinate system A. Note that tihs transforms a plane in the opposite sense in relation
// to how the same matrix would transform a point from coordinate system A to coordinate system B.
inline Plane operator*(const Plane& f, const Transform4x4& H) {
    return (Plane(f.x * H(0, 0) + f.y * H(1, 0) + f.z * H(2, 0),
                  f.x * H(0, 1) + f.y * H(1, 1) + f.z * H(2, 1),
                  f.x * H(0, 2) + f.y * H(1, 2) + f.z * H(2, 2),
                  f.x * H(0, 3) + f.y * H(1, 3) + f.z * H(2, 3) + f.w));
}

#endif //CPP_MATH_TRANSFORM4X4_H
