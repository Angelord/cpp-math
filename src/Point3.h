//
// Created by Angel on 11/16/2020.
//

#ifndef CPP_MATH_POINT3_H
#define CPP_MATH_POINT3_H

#include "Vector3.h"

struct Point3 : Vector3 {

    Point3() = default;

    Point3(float a, float b, float c) : Vector3(a, b, c) {}
};

inline Point3 operator+ (const Point3& a, const Vector3& b) {
    return (Point3(a.x + b.x, a.y + b.y, a.z + b.z));
}

inline Vector3 operator -(const Point3& a, const Point3& b) {
    return (Vector3(a.x - b.x, a.y - b.y, a.z - b.z));
}

#endif //CPP_MATH_POINT3_H
