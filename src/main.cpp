#include <iostream>
#include "Vector3.h"
#include "Vector4.h"
#include "Point3.h"
#include "Rotation.h"
#include "Reflection.h"
#include "Scale.h"
#include "Skew.h"

int main() {

    Vector3 vec(3, 2, 1);

    std::cout << "New Vector : " << vec << std::endl;

    return 0;
}