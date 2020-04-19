//
// Created by Almoxis on 4/19/2020.
//

#ifndef CPP_MATH_VECTOR3_H
#define CPP_MATH_VECTOR3_H


#include <string>
#include <sstream>

struct Vector3;

Vector3 operator-(const Vector3& lhs, const Vector3& rhs);

struct Vector3 {

    float x, y, z;

    Vector3() : x(0.0f), y(0.0f), z(0.0f) { }

    Vector3(float x, float y, float z) : x(x), y(y), z(z) { }

    Vector3(const Vector3& other) = default;

    static float Dot(const Vector3& lhs, const Vector3& rhs) {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    static Vector3 Cross(const Vector3& lhs, const Vector3& rhs) {
        return Vector3(
            lhs.y * rhs.z - lhs.z * rhs.y,
            lhs.z * rhs.x - lhs.x * rhs.z,
            lhs.x * rhs.y - lhs.y * rhs.x
        );
    }

    static float Distance(const Vector3& lhs, const Vector3& rhs) {
        return (rhs - lhs).GetMagnitude();
    }

    void Set(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    float GetMagnitude() {
        return sqrt(GetMagnitudeSq());
    }

    float GetMagnitudeSq() {
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
};

std::ostream& operator<<(std::ostream& os, const Vector3& vec) {
    os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
    return os;
}

Vector3 operator*(const Vector3& lhs, float rhs) {
    return Vector3(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}

Vector3 operator*(float lhs, const Vector3& rhs) {
    return operator*(rhs, lhs);
}

Vector3 operator/(const Vector3& lhs, float rhs) {
    return Vector3(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
}

bool operator==(const Vector3& lhs, const Vector3& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

Vector3 operator+(const Vector3& lhs, const Vector3& rhs) {
    return Vector3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

Vector3 operator-(const Vector3& lhs, const Vector3& rhs) {
    return Vector3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

#endif //CPP_MATH_VECTOR3_H
