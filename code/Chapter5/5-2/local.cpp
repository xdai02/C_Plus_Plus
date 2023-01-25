#include <iostream>

using namespace std;

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "swap(): a = " << a << ", b = " << b << endl;
}

int main() {
    int a = 1;
    int b = 2;

    cout << "Before: a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "After: a = " << a << ", b = " << b << endl;

    return 0;
}