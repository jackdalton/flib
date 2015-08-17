#include "flib.h"
#include <iostream>

int main() {
    Fraction f1(1, 2);
    std::cout << f1.get(F_DENOMINATOR) << std::endl;
    return 0;
}
