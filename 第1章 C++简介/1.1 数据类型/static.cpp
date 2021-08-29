#include <iostream>

using namespace std;

void foo() {
    static int n = 1;
    cout << "n = " << n << endl;
    n++;
}

int main() {
    for(int i = 0; i < 5; i++) {
        foo();
    }
    return 0;
}