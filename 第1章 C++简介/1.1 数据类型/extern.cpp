#include <iostream>

using namespace std;

extern int n;
extern void foo();

int main() {
    cout << n << endl;
    foo();
    return 0;
}