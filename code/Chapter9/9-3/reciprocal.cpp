#include <iostream>

using namespace std;

typedef struct {
    int numerator;
    int denominator;
} Fraction;

void reciprocal(Fraction *f) {
    if (f->numerator == 0) {
        cerr << "Error: Denominator cannot be zero." << endl;
        exit(1);
    } else {
        int temp = f->numerator;
        f->numerator = f->denominator;
        f->denominator = temp;
    }
}

int main() {
    Fraction fraction = {2, 5};  // 2/5

    cout << "Reciprocal of ";
    cout << fraction.numerator << "/" << fraction.denominator << " is ";
    reciprocal(&fraction);
    cout << fraction.numerator << "/" << fraction.denominator << endl;

    return 0;
}