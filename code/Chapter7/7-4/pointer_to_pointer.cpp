#include <iostream>

using namespace std;

int main() {
    int data = 5;
    int *p = &data;
    int **q = &p;

    cout << "data = " << data << endl;
    cout << "*p = " << *p << endl;
    cout << "**q = " << **q << endl;

    cout << "Address of data = " << &data << endl;
    cout << "Address of p = " << &p << endl;
    cout << "Address of q = " << &q << endl;

    cout << "Value of p = " << p << endl;
    cout << "Value of q = " << q << endl;

    return 0;
}