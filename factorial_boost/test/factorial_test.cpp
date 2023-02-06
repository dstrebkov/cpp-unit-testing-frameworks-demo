#define BOOST_TEST_MODULE factorial_boost

#include <boost/test/included/unit_test.hpp>

#include <factorial_boost/include/factorial.h>

BOOST_AUTO_TEST_CASE(FactorialTest) {
    BOOST_CHECK(factorial_boost::factorial(1) == 1);
    BOOST_CHECK(factorial_boost::factorial(2) == 2);
    BOOST_CHECK(factorial_boost::factorial(3) == 6);
}
