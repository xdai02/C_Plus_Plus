#include <iostream>
#include <iomanip>
#include "util.h"

using namespace std;

int main() {
    double arr[] = {3.1, 2.8, 1.3, 4.7, 5.6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Test data: ";
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(2) << arr[i] << " ";
    }
    cout << endl;

    cout << "Max = " << fixed << setprecision(2) << max(arr, n) << endl;
    cout << "Min = " << fixed << setprecision(2) << min(arr, n) << endl;
    cout << "Sum = " << fixed << setprecision(2) << sum(arr, n) << endl;
    cout << "Average = " << fixed << setprecision(2) << average(arr, n) << endl;

    cout << "0.1 + 0.2 == 0.3? " << boolalpha << (0.1 + 0.2 == 0.3) << endl;
    cout << "double_equal(0.1 + 0.2, 0.3)? " << boolalpha << double_equal(0.1 + 0.2, 0.3) << endl;
    
    return 0;
}