//
// Created by Almoxis on 11/20/2020.
//

#ifndef CPP_MATH_QUATERNION_H
#define CPP_MATH_QUATERNION_H

#include "Vector3.h"
#include "Matrix3x3.h"

struct Quaternion {

    float x, y, z, w;

    Quaternion() = default;

    Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    Quaternion(const Vector3 &vec, float s) : x(vec.x), y(vec.y), z(vec.z), w(s) {}

    [[nodiscard]] const Vector3& GetVectorPart() const {
        return (reinterpret_cast<const Vector3 &>(x));
    }

    // Generates a rotation matrix that performs the same rotation as the quaternion
    Matrix3x3 GetRotationMatrix();

    void SetRotationMatrix(const Matrix3x3 &m);
};

Quaternion operator*(const Quaternion &q1, const Quaternion &q2) {
    return (Quaternion(
            q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
            q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x,
            q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w,
            q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z));
}

#endif //CPP_MATH_QUATERNION_H
