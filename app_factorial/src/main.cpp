#include <iostream>

#include "../../factorial_catch2/include/factorial.h"
#include "../../factorial_doctest/include/factorial.h"
#include "../../factorial_gtest/include/factorial.h"
#include "../../factorial_lest/include/factorial.h"

#ifdef BUILD_FACTORIAL_BOOST_TEST_LIB
#   include "../../factorial_boost/include/factorial.h"
#endif // BUILD_FACTORIAL_BOOST_TEST_LIB

int main() {
#ifdef BUILD_FACTORIAL_BOOST_TEST_LIB
    std::cout << "[BoostTest]:  factorial(3) = " << factorial_boost::factorial(3) << std::endl;
#endif // BUILD_FACTORIAL_BOOST_TEST_LIB

    std::cout << "[Catch2]:     factorial(3) = " << factorial_catch2::factorial(3) << std::endl;
    std::cout << "[doctest]:    factorial(3) = " << factorial_doctest::factorial(3) << std::endl;
    std::cout << "[GoogleTest]: factorial(3) = " << factorial_gtest::factorial(3) << std::endl;
    std::cout << "[lest]:       factorial(3) = " << factorial_lest::factorial(3) << std::endl;

    return EXIT_SUCCESS;
}
