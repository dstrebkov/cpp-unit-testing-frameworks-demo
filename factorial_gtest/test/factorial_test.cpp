#include <gtest/gtest.h>

#include <factorial_gtest/include/factorial.h>

TEST(GoogleTest_FactorialTest, GoogleTest_BasicEqualAssertions) {
    EXPECT_EQ(factorial_gtest::factorial(1), 1);
    EXPECT_EQ(factorial_gtest::factorial(2), 2);
    EXPECT_EQ(factorial_gtest::factorial(3), 6);
}
