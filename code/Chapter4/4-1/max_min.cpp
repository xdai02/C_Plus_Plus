#include <iostream>

using namespace std;

int main() {
    int num[] = {7, 6, 2, 9, 3, 1, 4, 0, 5, 8};
    int n = sizeof(num) / sizeof(num[0]);
    int max = num[0];
    int min = num[0];

    for (int i = 1; i < n; i++) {
        if (num[i] > max) {
            max = num[i];
        }
        if (num[i] < min) {
            min = num[i];
        }
    }
    
    cout << "Max = " << max << endl;
    cout << "Min = " << min << endl;
    return 0;
}