#include <iostream>

using namespace std;

void swap(int &data1, int &data2) {
    int temp = data1;
    data1 = data2;
    data2 = temp;
}

int main() {
    int a = 3;
    int b = 5;

    cout << "Before: a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "After: a = " << a << ", b = " << b << endl;
    return 0;
}