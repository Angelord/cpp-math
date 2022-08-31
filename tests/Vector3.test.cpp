//
// Created by Almoxis on 4/19/2020.
//

#include "catch.hpp"
#include "../src/Vector3.h"

TEST_CASE("Test Scalar Multiplication") {

    Vector3 vec(1, 2, 3);

    REQUIRE(2 * vec == Vector3(2, 4, 6));

    REQUIRE(vec * 2 == Vector3(2, 4, 6));
}

TEST_CASE("Compound Scalar Multiplication") {

    Vector3 vec(1, 2, 3);
    vec *= 3;

    REQUIRE(vec == Vector3(3, 6, 9));
}

TEST_CASE("Test Scalar Division") {

    REQUIRE(Vector3(8, 4, 6) / 2 == Vector3(4, 2, 3));
}

TEST_CASE("Compound Scalar Division") {

    Vector3 vec(8, 4, 6);

    vec /= 2;

    REQUIRE(vec == Vector3(4, 2, 3));
}

TEST_CASE("Test Vector Addition") {

    REQUIRE((Vector3(2, 11, 5) + Vector3(18, 215, 6)) == Vector3(20, 226, 11));
}

TEST_CASE("Compound Vector Addition") {

    Vector3 lhs(2, 11, 5);

    lhs += Vector3(18, 215, 6);

    REQUIRE(lhs == Vector3(20, 226, 11));
}

TEST_CASE("Test Vector Subtraction") {

    REQUIRE((Vector3(7, 19, 100) - Vector3(-6, 20, 5)) == Vector3(13, -1, 95));
}

TEST_CASE("Compound Vector Subtraction") {

    Vector3 lhs(7, 19, 100);

    lhs -= Vector3(-6, 20, 5);

    REQUIRE(lhs == Vector3(13, -1, 95));
}

TEST_CASE("Test Get Magnitude") {
    Vector3 lhs(4, 3, 0);

    REQUIRE(lhs.Magnitude() == 5.0f);
}

TEST_CASE("Test Get Magnitude Sq") {
    Vector3 lhs(4, 3, 0);

    REQUIRE(lhs.MagnitudeSq() == 25.0f);
}

TEST_CASE("Test Dot Product") {

    Vector3 lhs(2, 2, 1);

    Vector3 rhs(1, -2, 0);

    REQUIRE(Vector3::Dot(lhs, rhs) == -2.0f);
}

TEST_CASE("Test Cross Product") {

    REQUIRE(Vector3::Cross(Vector3(2, 2, 1), Vector3(1, -2, 0)) == Vector3(2, 1, -6));

    REQUIRE(Vector3::Cross(Vector3(4, 6, 12), Vector3(54, -18, 4)) == Vector3(240, 632, -396));
}

TEST_CASE("Test Distance") {

    REQUIRE(Vector3::Distance(Vector3(4, 0, 0), Vector3(0, 3, 0)) == 5.0f);
}

TEST_CASE("Reflection") {

    REQUIRE(Vector3::Reflect(Vector3(0, 1, 0), Vector3(1, 0, 0)) == Vector3(-1, 0, 0));
    REQUIRE(Vector3::Reflect(Vector3(1, 0, 0), Vector3(1, 0, 0)) == Vector3(1, 0, 0));
}

TEST_CASE("Access member by index") {

    Vector3 vec(1, 2, 3);

    REQUIRE(vec[0] == 1);
    REQUIRE(vec[1] == 2);
    REQUIRE(vec[2] == 3);
}

TEST_CASE("Can be normalized") {

    REQUIRE(Vector3(5, 6, 3).Normalized().Magnitude() == 1);
    REQUIRE(Vector3(-15, -3, 3).Normalized().Magnitude() == 1);
    REQUIRE(Vector3(215, 4, -50).Normalized().Magnitude() == 1);
}