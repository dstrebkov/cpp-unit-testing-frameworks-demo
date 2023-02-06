#include "../include/factorial.h"

namespace factorial_gtest {
    int factorial(int x) {
        return x <= 1 ? x : factorial(x - 1) * x;
    }
}
