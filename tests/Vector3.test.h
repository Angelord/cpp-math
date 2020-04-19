//
// Created by Almoxis on 4/19/2020.
//

#ifndef CPP_MATH_VECTOR3_TEST_H
#define CPP_MATH_VECTOR3_TEST_H
#include <iostream>
#include "../src/Vector3.h"
#include "asserts.h"

namespace Vector3Tests {

    void TestScalarMultiplication() {

        Vector3 vec(1, 2, 3);

        Assert::Equal(2 * vec, Vector3(2, 4, 6), "Invalid result from rhs scalar multiplication");

        Assert::Equal(vec * 2, Vector3(2, 4, 6), "Invalid result from lhs scalar multiplication");

        vec *= 3;

        Assert::Equal(vec, Vector3(3, 6, 9), "Invalid result from compound assignment scalar multiplication");
    }

    void TestScalarDivision() {

        Vector3 vec(8, 4, 6);

        Assert::Equal(vec / 2, Vector3(4, 2, 3), "Invalid result from scalar division");

        vec /= 2;

        Assert::Equal(vec, Vector3(4, 2, 3), "Invalid reuslt form compound assignment scalar division");
    }

    void TestVectorAddition() {

        Vector3 lhs(2, 11, 5);

        Vector3 rhs(18, 215, 6);

        Vector3 expectedResult(20, 226, 11);

        Assert::Equal(lhs + rhs, expectedResult, "Invalid result from vector addition");

        lhs += rhs;

        Assert::Equal(lhs, expectedResult, "Invalid result from compound assignment vector addition");
    }

    void TestVectorSubtraction() {

        Vector3 lhs(7, 19, 100);

        Vector3 rhs(-6, 20, 5);

        Vector3 expectedResult(13, -1, 95);

        Assert::Equal(lhs - rhs, expectedResult, "Invalid result from vector subtraction");

        lhs -= rhs;

        Assert::Equal(lhs, expectedResult, "Invalid result from compound assignment vector subtraction");
    }

    void TestGetMagnitude() {
        Vector3 lhs(4, 3, 0);

        Assert::Equal(lhs.GetMagnitude(), 5.0f, "Invalid result from get magnitude");
    }

    void TestGetMagnitudeSq() {
        Vector3 lhs(4, 3, 0);

        Assert::Equal(lhs.GetMagnitudeSq(), 25.0f, "Invalid result from get magnitude squared");
    }

    void TestDotProduct() {

        Vector3 lhs(2, 2, 1);

        Vector3 rhs(1, -2, 0);

        Assert::Equal(Vector3::Dot(lhs, rhs), -2.0f, "Invalid result for dot product");
    }

    void TestCrossProduct() {

        Vector3 lhs(2, 2, 1);

        Vector3 rhs(1, -2, 0);

        Assert::Equal(Vector3::Cross(Vector3(2, 2, 1), Vector3(1, -2, 0)), Vector3(2, 1, -6),
                "Invalid result from cross product");

        Assert::Equal(Vector3::Cross(Vector3(4, 6, 12), Vector3(54, -18, 4)), Vector3(240, 632, -396),
                "Invalid result from cross product");
    }

    void TestDistance() {

        Vector3 lhs(4, 0, 0);

        Vector3 rhs(0, 3, 0);

        Assert::Equal(Vector3::Distance(Vector3(4, 0, 0), Vector3(0, 3, 0)), 5.0f,
                "Invalid result for distance");
    }
}

#endif //CPP_MATH_VECTOR3_TEST_H
