#include <lest/lest.hpp>
#include <trompeloeil.hpp>

#include <factorial_lest/include/factorial.h>

#define CASE( name ) lest_CASE( specification, name )

static lest::tests specification;

class FactorialMocked {
public:
    MAKE_MOCK1(factorial, int(int));
};

void function_to_test(FactorialMocked * object) {
    auto r = object->factorial(3); // r would be set to 555 according to below
}

CASE("lest_FactorialTest") {
    EXPECT(factorial_lest::factorial(1) == 1);
    EXPECT(factorial_lest::factorial(2) == 2);
    EXPECT(factorial_lest::factorial(3) == 6);
}

CASE("lest_FactorialMockedTest: Expecting 1 call to FactorialMocked::factorial()") {
    FactorialMocked mock;

    REQUIRE_CALL(mock, factorial(3))
        .TIMES(1)
        .RETURN(555); // telling to the caller that return value is 555

    function_to_test(&mock);
}

// With lest, you always provide your own main()
// lest main() function below is adapted for Trompeloeil
int main(int argc, char * argv[]) {
    std::ostream & stream = std::cout;
    
    trompeloeil::set_reporter(
        [&stream]( trompeloeil::severity severity, const char * file, unsigned long line, std::string const & msg )
    {
        stream << msg << std::endl;
        throw lest::message{ "", lest::location{ line ? file : "[file/line unavailable]", int(line) }, "", msg };
    });

    return lest::run(specification, argc, argv, stream);
}
