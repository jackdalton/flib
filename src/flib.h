#include <math.h>

int F_NUMERATOR = 0;
int F_DENOMINATOR = 1;

class Fraction {
public:
    Fraction(double numerator = 0, double denominator = 1) {
        n = numerator;
        d = denominator;
    }
    double get(int target) {
        if (target == 0) {
            return n;
        } else if (target == 1) {
            return d;
        }
    }
    bool set(double numerator = 0, double denominator = 1) {
        if (denominator != 0) {
            n = numerator;
            d = denominator;
            return true;
        } else {
            return false;
        }
    }
private:
    double n, d;
};
