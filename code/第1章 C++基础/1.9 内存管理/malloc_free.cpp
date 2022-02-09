#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    const int n = 10;
    int *arr = (int *)malloc(sizeof(int) * n);
    if(!arr) {
        cerr << "Memory allocation failed." << endl;
        return 1;
    }
    for(int i = 0; i < n; i++) {
        arr[i] = i;
        cout << arr[i] << " ";
    }
    cout << endl;
    free(arr);
    return 0;
}