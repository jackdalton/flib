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
private:
    double n, d;
};
