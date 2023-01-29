#include <iostream>
#include <exception>

using namespace std;

int main() {
    try {
        int *arr = new int[0xfffffffff];
        delete arr;
    } catch (bad_alloc &e) {
        cerr << e.what() << endl;
    }

    return 0;
}