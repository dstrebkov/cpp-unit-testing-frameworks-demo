#include "../include/factorial.h"

namespace factorial_boost {
    int factorial(int x) {
        return x <= 1 ? x : factorial(x - 1) * x;
    }
}
