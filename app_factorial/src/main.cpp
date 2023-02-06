#include <iostream>
#include <include/lib_factorial_catch2/factorial.h>
#include <include/lib_factorial_gtest/factorial.h>
#include <include/lib_factorial_doctest/factorial.h>
#include <include/lib_factorial_boost/factorial.h>

int main() {
    std::cout << "[Catch2]:     factorial(3) = " << lib_factorial_catch2::factorial(3) << std::endl;
    std::cout << "[GoogleTest]: factorial(3) = " << lib_factorial_gtest::factorial(3) << std::endl;
    std::cout << "[doctest]:    factorial(3) = " << lib_factorial_doctest::factorial(3) << std::endl;
    std::cout << "[BoostTest]:  factorial(3) = " << lib_factorial_boost::factorial(3) << std::endl;
    return EXIT_SUCCESS;
}
