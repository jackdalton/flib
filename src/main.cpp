#include "flib.h"
#include <iostream>

int main() {
	Fraction f1(1, 2);
	bool passed = true;
	if (f1.get(F_NUMERATOR) != 1) passed = false;
	if (f1.get(F_DENOMINATOR) != 2) passed = false;
	if (!f1.set(2, 1)) passed = false;
	if (f1.get(F_NUMERATOR) != 2) passed = false;
	if (f1.get(F_DENOMINATOR) != 1) passed = false;
	f1.set(1, 2);
	if (f1.get(F_DECIMAL) != 0.5) passed = false;
	if (f1.toString() != "1/2") passed = false;
	f1.set(2, 4);
	Fraction f2 = f1.reduce();
	if (f2.get(F_NUMERATOR) != 1) passed = false;
	if (f2.get(F_DENOMINATOR) != 2) passed = false;
	if (!f2.equalTo(f1)) passed = false;
	if (f2.greaterThan(f1)) passed = false;
	f2.set(2, 3);
	if (!f2.greaterThan(f1)) passed = false;
	if (!f1.lessThan(f2)) passed = false;
	if (passed) {
		std::cout << "Test passed." << std::endl;
	}
	else {
		std::cout << "Error: Test failed." << std::endl;
	}
	return 0;
}