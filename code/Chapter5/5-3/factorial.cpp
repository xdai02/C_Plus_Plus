#include <iostream>

using namespace std;

int factorial(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n-1);
}

int main() {
    cout << "5! = " << factorial(5) << endl;
    return 0;
}