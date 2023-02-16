#include <criterion/criterion.h>
#include <criterion/trompeloeil.hpp>

#include <factorial_criterion/include/factorial.h>

class FactorialMocked {
public:
    MAKE_MOCK1(factorial, int(int));
};

void function_to_test(FactorialMocked * object) {
    auto r = object->factorial(3); // r would be set to 333 according to below
}

Test(asserts, Criterion_FactorialTest) {
    cr_assert(factorial_criterion::factorial(1) == 1);
    cr_assert(factorial_criterion::factorial(2) == 2);
    cr_assert(factorial_criterion::factorial(3) == 6);
}

Test(assert, Criterion_MockedFactorial) {
    FactorialMocked mock;

    REQUIRE_CALL(mock, factorial(3))
        .TIMES(1)
        .RETURN(333); // telling to the caller that return value is 333

    function_to_test(&mock);
}
