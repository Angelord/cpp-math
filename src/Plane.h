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

    /// Calculates the line determined by point p and vector v at which two planes intersect.
    /// If the normal vectors of the planes are parallel, the function returns false.
    static bool IntersectTwoPlanes(const Plane& f1, const Plane& f2, Point3* p, Vector3* v) {

        const Vector3& n1 = f1.GetNormal();
        const Vector3& n2 = f2.GetNormal();

        *v = Vector3::Cross(n1, n2);
        float det = Vector3::Dot(n1, n2);

        if(fabs(det) > FLT_MIN) {
            *p = (Vector3::Cross(*v, n2) * f1.w + Vector3::Cross(n1, *v) * f2.w) / det;
            return true;
        }

        return false;
    }

    /// Calculates the point p at which three planes intersect. Returns true if such a point exists.
    /// If the normal vectors are not linearly independent, then the function returns false.
    static bool IntersectThreePlanes(const Plane& f1, const Plane& f2,
                                    const Plane& f3, Point3* p) {
        const Vector3& n1 = f1.GetNormal();
        const Vector3& n2 = f2.GetNormal();
        const Vector3& n3 = f3.GetNormal();

        Vector3 n1xn = Vector3::Cross(n1, n2);
        float det = Vector3::Dot(n1xn, n3);

        if(fabs(det) > FLT_MIN) {

            *p = (Vector3::Cross(n3, n2) * f1.w + Vector3::Cross(n1, n3) * f2.w - n1xn * f3.w) / det;

            return true;
        }

        return false;
    }
};


#endif //CPP_MATH_PLANE_H
