#include "../include/factorial.h"

namespace factorial_lest {
    int factorial(int x) {
        return x <= 1 ? x : factorial(x - 1) * x;
    }
}
