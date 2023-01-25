#include <iostream>

using namespace std;

int main() {
    int arr[5] = {7, 6, 2, 9, 3};
    int sum = 0;
    for (int elem : arr) {
        sum += elem * elem;
    }
    cout << "Square sum = " << sum << endl;

    return 0;
}