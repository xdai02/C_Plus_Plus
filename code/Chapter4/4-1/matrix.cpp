#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int A[3][2] = {
        {1, 3},
        {1, 0},
        {1, 2}
    };
    int B[3][2] = {
        {0, 0},
        {7, 5},
        {2, 1}
    };
    int C[3][2];

    cout << "Matrix Addition" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] + B[i][j];
            cout << setw(3) << C[i][j];
        }
        cout << endl;
    }
    
    cout << "Matrix Subtraction" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] - B[i][j];
            cout << setw(3) << C[i][j];
        }
        cout << endl;
    }
    
    return 0;
}