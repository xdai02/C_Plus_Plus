#include <iostream>

using namespace std;

void print_2d_array(int arr[], int n, int row, int col) {
    if (n != row * col) {
        return;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i * col + j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int row, col;
    cout << "Enter row: ";
    cin >> row;
    cout << "Enter column: ";
    cin >> col;

    print_2d_array(arr, n, row, col);

    return 0;
}