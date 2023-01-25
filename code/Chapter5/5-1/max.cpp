#include <iostream>

using namespace std;

int max(int num1, int num2);  // function prototype

int main() {
    cout << max(4, 12) << endl;
    cout << max(54, 33) << endl;
    cout << max(-999, -774) << endl;
    return 0;
}

int max(int num1, int num2) {
    // if(num1 > num2) {
    //     return num1;
    // } else {
    //     return num2;
    // }

    return num1 > num2 ? num1 : num2;
}