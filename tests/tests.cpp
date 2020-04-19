//
// Created by Almoxis on 4/19/2020.
//

#include "Vector3.test.h"

int main() {

    Vector3Tests::TestScalarMultiplication();

    Vector3Tests::TestScalarDivision();

    Vector3Tests::TestVectorAddition();

    Vector3Tests::TestVectorSubtraction();

    Vector3Tests::TestGetMagnitude();

    Vector3Tests::TestGetMagnitudeSq();

    Vector3Tests::TestDotProduct();

    Vector3Tests::TestCrossProduct();

    Vector3Tests::TestDistance();
}