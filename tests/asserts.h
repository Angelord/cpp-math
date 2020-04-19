//
// Created by Almoxis on 4/19/2020.
//

#ifndef CPP_MATH_ASSERTS_H
#define CPP_MATH_ASSERTS_H

#include <sstream>

struct Assert {

    static void True(bool value, const std::string& msg) {
        if(!value) { std::cerr << "\t" << msg << std::endl; }
    }

    template <typename T>
    static void Equal(T actual, T expected, const std::string& msg) {
        std::stringstream fullMsg;

        fullMsg << msg;
        fullMsg << "\n\tExpected : " << expected;
        fullMsg << "\n\tActual : " << actual;

        True(actual == expected, fullMsg.str());
    }
};

#endif //CPP_MATH_ASSERTS_H
