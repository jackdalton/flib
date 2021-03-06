#pragma once

#include <math.h>
#include <string>
#include <sstream>

int F_NUMERATOR = 0;
int F_DENOMINATOR = 1;
int F_DECIMAL = 2;
int F_PERCENT = 3;

class Fraction {
public:
	Fraction(double numerator = 0, double denominator = 1) {
		n = numerator;
		d = denominator;
	}
	double get(int target) {
		if (target == 0) {
			return n;
		}
		else if (target == 1) {
			return d;
		}
		else if (target == 2) {
			return n / d;
		}
		else if (target == 3) {
		    return (n / d) * 100;
		}
	}
	Fraction reduce() {
		double ld = d;
		double ln = n;
		for (int i = d * n; i > 1; i--) {
			if ((fmod(d, i) == 0) && (fmod(n, i) == 0)) {
				ln /= i;
				ld /= i;
			}
		}
		return Fraction(ln, ld);
	}
	bool greaterThan(Fraction f) {
		if (get(F_DECIMAL) > f.get(F_DECIMAL)) {
			return true;
		}
		return false;
	}
	double toPercent() {
		return get(F_PERCENT);
	}
	bool lessThan(Fraction f) {
		return !greaterThan(f);
	}
	Fraction multiplyBy(Fraction f) {
		return Fraction(n * f.get(F_NUMERATOR), d * f.get(F_DENOMINATOR));
	}
	Fraction divideBy(Fraction f) {
		return multiplyBy(Fraction(f.get(F_DENOMINATOR), f.get(F_NUMERATOR)));
	}
	bool equalTo(Fraction f) {
		if (f.get(F_DECIMAL) == get(F_DECIMAL)) {
			return true;
		}
		return false;
	}
	std::string toString() {
		std::stringstream st;
		st << n << "/" << d;
		return st.str();
	}
	bool set(double numerator = 0, double denominator = 1) {
		if (denominator != 0) {
			n = numerator;
			d = denominator;
			return true;
		}
		else {
			return false;
		}
	}
private:
	double n, d;
};
