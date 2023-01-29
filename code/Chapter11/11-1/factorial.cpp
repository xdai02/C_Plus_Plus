#include <iostream>
#include <exception>

using namespace std;

int factorial(int n) {
    if (n < 0) {
        throw "Factorial of negative numbers is not defined.";
    }

    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    try {
        int fact = factorial(n);
        cout << n << "! = " << fact << endl;
    } catch (const char *e) {
        cerr << e << endl;
    }

    return 0;
}