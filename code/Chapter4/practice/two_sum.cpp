#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Target: ";
    cin >> target;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                cout << "Index: " << i << ", " << j << endl;
            }
        }
    }

    return 0;
}