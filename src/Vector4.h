//
// Created by Angel on 11/16/2020.
//

#ifndef CPP_MATH_VECTOR4_H
#define CPP_MATH_VECTOR4_H

struct Vector4 {
    float x, y, z, w;

    Vector4() = default;

    Vector4(float a, float b, float c, float d) {
        x = a;
        y = b;
        z = c;
        w = d;
    }

    float &operator[](int i) {
        return ((&x)[i]);
    }

    const float &operator[](int i) const {
        return ((&x)[i]);
    }

    Vector4 &operator*=(float s) {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return (*this);
    }

    Vector4 &operator/=(float s) {
        s = 1.0F / s;
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return (*this);
    }

    Vector4 &operator+=(const Vector4 &v) {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
        return (*this);
    }

    Vector4 &operator-=(const Vector4 &v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        w -= v.w;
        return (*this);
    }
};

#endif //CPP_MATH_VECTOR4_H
