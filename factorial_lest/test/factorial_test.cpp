#include <lest/lest.hpp>

#include <factorial_lest/include/factorial.h>

const lest::test specification[] = {
    CASE("lest_FactorialTest") {
        EXPECT(factorial_lest::factorial(1) == 1);
        EXPECT(factorial_lest::factorial(2) == 2);
        EXPECT(factorial_lest::factorial(3) == 6);
    }
};

// With lest, you always provide your own main()
int main(int argc, char *argv[]) {
    if (int failures = lest::run(specification, argc, argv))
        return failures;
    
    return std::cout << "All tests passed\n", EXIT_SUCCESS;
}
