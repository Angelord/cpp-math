//
// Created by Angel Paunov Georgiev on 2020-12-01.
//

#ifndef CPP_MATH_LINE_H
#define CPP_MATH_LINE_H

#include "Point3.h"


struct Line {
    Vector3 direction;
    Vector3 moment;

    Line() = default;

    Line(float vx, float vy, float vz, float mx, float my, float mz) : direction(vx, vy, vz), moment(mx, my, mz) {
    }

    Line(const Vector3& v, const Vector3& m) : direction(v), moment(m) {
    }
};

// If u = q - p, then |u x v| gives the area of a parallelogram. The distance d is the height of the parallelogram.
// To find the height we divide |u x v| by |v|, which is its base.
inline float CalculateLinePointDist(const Point3& q, const Point3& p, const Vector3& v) {

    Vector3 a = Vector3::Cross(q - p, v);

    return (sqrt(Vector3::Dot(a, a) / Vector3::Dot(v, v)));
}

inline float CalculateLineLineDist(const Point3& p1, const Vector3& v1,
                                    const Point3& p2, const Vector3& v2) {

    Vector3 dp = p2 - p1;

    float v12 = Vector3::Dot(v1, v1);
    float v22 = Vector3::Dot(v2, v2);
    float v1v2 = Vector3::Dot(v1, v2);

    float det = v1v2 * v1v2 - v12 * v22;

    if(fabs(det) > FLT_MIN) {
        det = 1.0f / det;


        float dpv1 = Vector3::Dot(dp, v1);
        float dpv2 = Vector3::Dot(dp, v2);
        float t1 = (v1v2 * dpv2 - v22 * dpv1) * det;
        float t2 = (v12 * dpv2 - v1v2 * dpv1) * det;

        return (dp + v2 * t2 - v1 * t1).Magnitude();
    }

    // The lines are nearly parallel.

    Vector3 a = Vector3::Cross(dp, v1);
    return (sqrt(Vector3::Dot(a, a) / v12));
}

#endif //CPP_MATH_LINE_H
