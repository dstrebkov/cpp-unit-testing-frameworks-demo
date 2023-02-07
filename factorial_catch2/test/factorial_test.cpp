#include <catch2/catch_test_macros.hpp>
#include <fakeit.hpp>

#include <factorial_catch2/include/factorial.h>

TEST_CASE("Catch2_FactorialTest", "[Catch2_FactorialTest]") {
    REQUIRE(factorial_catch2::factorial(1) == 1);
    REQUIRE(factorial_catch2::factorial(2) == 2);
    REQUIRE(factorial_catch2::factorial(3) == 6);
}

using namespace fakeit;

struct FactorialStruct {
    virtual ~FactorialStruct() = default;
    virtual int factorial(int) = 0;
};

TEST_CASE("Catch2_MockedFactorialTest", "[Catch2_FactorialTest]") {
    Mock<FactorialStruct> mock;

    When(Method(mock, factorial).Using(3)).Return(6);

    auto result = mock.get().factorial(3);

    REQUIRE(result == 6); // verify using Catch2

    Verify(Method(mock, factorial).Using(3)); // verify factorial(3) was invoked
    Verify(Method(mock, factorial).Using(3)).Once(); // verify factorial(3) was invoked exactly once
}
