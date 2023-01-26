#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * Solve quadratic equation ax^2 + bx + c = 0.
 * @param a coefficient of x^2
 * @param b coefficient of x
 * @param c constant
 * @param x1 pointer to the first root
 * @param x2 pointer to the second root
 * @return true if the equation has real roots, false otherwise.
 */
bool solver(double a, double b, double c, double *x1, double *x2) {
    double delta = b * b - 4 * a * c;
    if (delta < 0) {
        return false;
    }
    *x1 = (-b + sqrt(delta)) / (2 * a);
    *x2 = (-b - sqrt(delta)) / (2 * a);
    return true;
}

int main() {
    double a, b, c;
    double x1, x2;

    cout << "Quadratic equation ax^2 + bx + c = 0" << endl;
    cout << "Enter coefficients a, b, c: ";
    cin >> a >> b >> c;

    if (solver(a, b, c, &x1, &x2)) {
        cout << fixed << setprecision(2) 
             << "x1 = "  << x1 << ", x2 = " << x2 << endl;
    } else {
        cout << "No real roots" << endl;
    }

    return 0;
}