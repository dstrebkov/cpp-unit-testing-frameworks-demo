#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <fakeit.hpp>

#include <factorial_doctest/include/factorial.h>

using namespace fakeit;

struct FactorialStruct {
    virtual ~FactorialStruct() = default;
    virtual int factorial(int) = 0;
};

TEST_CASE("doctest_FactorialTest") {
    CHECK((factorial_doctest::factorial(1) == 1));
    CHECK((factorial_doctest::factorial(2) == 2));
    CHECK((factorial_doctest::factorial(3) == 6));

    Mock<FactorialStruct> mock;
    When(Method(mock, factorial).Using(3)).Return(6);
    auto result = mock.get().factorial(3);
    REQUIRE((result == 6)); // verify using Catch2
}
