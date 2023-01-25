#include <iostream>

using namespace std;

int a, b;

void swap() {
    int temp = a;
    a = b;
    b = temp;
    cout << "swap(): a = " << a << ", b = " << b << endl;
}

int main() {
    a = 1;
    b = 2;

    cout << "Before: a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "After: a = " << a << ", b = " << b << endl;

    return 0;
}