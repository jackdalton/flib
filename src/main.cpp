#include "flib.h"
#include <iostream>

int main() {
    Fraction f1(1, 2);
    bool passed = true;
    if (f1.get(F_NUMERATOR) != 1) {
        passed = false;
    }
    if (f1.get(F_DENOMINATOR) != 2) {
        passed = false;
    }
    if (!f1.set(2, 1)) {
        passed = false;
    }
    if (f1.get(F_NUMERATOR) != 2 ) {
        passed = false;
    }
    if (f1.get(F_DENOMINATOR) != 1) {
        passed = false;
    }
    if (passed) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Error: Test failed." << std::endl;
    }
    return 0;
}
