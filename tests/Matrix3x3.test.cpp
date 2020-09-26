//
// Created by Almoxis on 9/26/2020.
//

#include "catch.hpp"
#include "../src/Matrix3x3.h"

TEST_CASE("Allows data access via indexing", "Matrix4x4") {

    Matrix3x3 mat(
            1, 2, 3,
            4, 5, 6,
            7, 8, 9
    );

    REQUIRE(mat(0, 0) == 1);
    REQUIRE(mat(0, 1) == 2);
    REQUIRE(mat(0, 2) == 3);
    REQUIRE(mat(1, 0) == 4);
    REQUIRE(mat(1, 1) == 5);
    REQUIRE(mat(1, 2) == 6);
    REQUIRE(mat(2, 0) == 7);
    REQUIRE(mat(2, 1) == 8);
    REQUIRE(mat(2, 2) == 9);
}

TEST_CASE("Allows data access via vector indexing", "Matrix4x4") {

    Matrix3x3 mat(
            1, 2, 3,
            4, 5, 6,
            7, 8, 9
    );

    REQUIRE(mat[0] == Vector3(1, 2, 3));
    REQUIRE(mat[1] == Vector3(4, 5, 6));
    REQUIRE(mat[2] == Vector3(7, 8, 9));
}

TEST_CASE("Matrix Multiplication", "Matrix4x3") {

    Matrix3x3 mat(
            1, 2, 3,
            4, 5, 6,
            7, 8, 9
    );

    Matrix3x3 result = mat * mat;

    REQUIRE(result(0, 0) == 30);
    REQUIRE(result(0, 1) == 36);
}

TEST_CASE("Matrix-Vector Multiplication", "Matrix4x3") {

    Matrix3x3 mat(
            1, 2, 3,
            4, 5, 6,
            7, 8, 9
    );

    Vector3 result = mat * Vector3(1, 2, 3);

    REQUIRE(result.x == 14);
    REQUIRE(result.y == 32);
    REQUIRE(result.z == 50);
}