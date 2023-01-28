#include <iostream>
#include <cstdlib>

using namespace std;

int *generate_fibonacci(int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        return NULL;
    }

    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr;
}

int main() {
    int n = 10;
    int *arr = generate_fibonacci(n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    free(arr);
    return 0;
}