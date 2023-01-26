#include <iostream>

using namespace std;

int main() {
    int arr[] = {4, 1, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *p = arr;

    cout << "Address of arr: " << arr << endl;
    for (int i = 0; i < n; i++) {
        cout << "Address of arr[" << i << "]: " << &arr[i] << endl;
    }

    cout << "Value of p: " << p << endl;
    for (int i = 1; i < n; i++) {
        cout << "Value of p + " << i << ": " << p + i << endl;
    }

    *p = 9;
    *(p + 1) = 8;
    *(p + 2) = 7;
    *(p + 3) = 6;

    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "]: " << arr[i] << endl;
    }

    return 0;
}