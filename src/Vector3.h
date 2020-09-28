//
// Created by Almoxis on 4/19/2020.
//

#ifndef CPP_MATH_VECTOR3_H
#define CPP_MATH_VECTOR3_H

#include <string>
#include <sstream>

struct Vector3;

inline Vector3 operator*(const Vector3& lhs, float rhs);

inline Vector3 operator*(float lhs, const Vector3& rhs);

inline Vector3 operator-(const Vector3& lhs, const Vector3& rhs);

inline Vector3 operator/(const Vector3& lhs, float rhs);

struct Vector3 {

    float x, y, z;

    Vector3() : x(0.0f), y(0.0f), z(0.0f) { }

    Vector3(float x, float y, float z) : x(x), y(y), z(z) { }

    Vector3(const Vector3& other) = default;

    static float Dot(const Vector3& lhs, const Vector3& rhs) {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    static Vector3 Project(const Vector3& a, const Vector3& b) {
        return (b * Dot(a, b) / Dot(b, b));
    }

    static Vector3 Reject(const Vector3& a, const Vector3& b) {
        return (a - b * (Dot(a, b) / Dot(b, b)));
    }

    static Vector3 Cross(const Vector3& lhs, const Vector3& rhs) {
        return Vector3(
            lhs.y * rhs.z - lhs.z * rhs.y,
            lhs.z * rhs.x - lhs.x * rhs.z,
            lhs.x * rhs.y - lhs.y * rhs.x
        );
    }

    static float Distance(const Vector3& lhs, const Vector3& rhs) {
        return (rhs - lhs).Magnitude();
    }

    void Set(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector3 Normalized() const {
        return ((*this) / this->Magnitude());
    }

    float Magnitude() const {
        return sqrt(MagnitudeSq());
    }

    float MagnitudeSq() const {
        return x * x + y * y + z * z;
    }

    Vector3& operator*=(float rhs) {
        x *= rhs; y *= rhs; z *= rhs;
        return *this;
    }

    Vector3& operator/=(float rhs) {
        x /= rhs; y /= rhs; z /= rhs;
        return *this;
    }

    Vector3& operator+=(const Vector3& rhs) {
        x += rhs.x; y += rhs.y; z += rhs.z;
        return *this;
    }

    Vector3& operator-=(const Vector3& rhs) {
        x -= rhs.x; y -= rhs.y; z -= rhs.z;
        return *this;
    }

    float& operator[](size_t i) {
        return ((&x)[i]);
    }

    const float& operator[](size_t i) const {
        return ((&x)[i]);
    }
};

inline Vector3 operator*(const Vector3& lhs, float rhs) {
    return Vector3(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}

inline Vector3 operator*(float lhs, const Vector3& rhs) {
    return operator*(rhs, lhs);
}

inline Vector3 operator/(const Vector3& lhs, float rhs) {
    return Vector3(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
}

inline bool operator==(const Vector3& lhs, const Vector3& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

inline Vector3 operator+(const Vector3& lhs, const Vector3& rhs) {
    return Vector3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

inline Vector3 operator-(const Vector3& lhs, const Vector3& rhs) {
    return Vector3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

// For debugging
inline std::ostream& operator<<(std::ostream& os, const Vector3& vec) {
    os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
    return os;
}

#endif //CPP_MATH_VECTOR3_H
