#include <iostream>

using namespace std;

#define SWAP(a, b) {int t; t = a; a = b; b = t;}

int main() {
    int a = 1;
    int b = 2;

    cout << "Before: a = " << a << ", b = " << b << endl;
    SWAP(a, b);
    cout << "After: a = " << a << ", b = " << b << endl;

    return 0;
}