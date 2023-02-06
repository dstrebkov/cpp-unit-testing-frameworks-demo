#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include <factorial_doctest/include/factorial.h>

TEST_CASE("FactorialTest") {
    CHECK((factorial_doctest::factorial(1) == 1));
    CHECK((factorial_doctest::factorial(2) == 2));
    CHECK((factorial_doctest::factorial(3) == 6));
}
