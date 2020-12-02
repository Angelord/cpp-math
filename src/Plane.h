//
// Created by Almoxis on 12/2/2020.
//

#ifndef CPP_MATH_PLANE_H
#define CPP_MATH_PLANE_H

#include "Vector3.h"
#include "Point3.h"

struct Plane {

    float x, y, z, w;

    Plane() = default;

    Plane(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    Plane(const Vector3& n, float d) : x(n.x), y(n.y), z(n.z), w(d) {}

    const Vector3& GetNormal() const {
        return (reinterpret_cast<const Vector3&>(x));
    }

    static float Dot(const Plane& f, const Vector3& v) {
        return (f.x * v.x + f.y * v.y + f.z * v.z);
    }

    static float Dot(const Plane& f, const Point3& p) {
        return (f.x * p.x + f.y * p.y + f.z * p.z + f.w);
    }
};


#endif //CPP_MATH_PLANE_H
