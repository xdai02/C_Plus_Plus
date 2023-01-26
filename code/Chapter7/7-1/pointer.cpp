#include <iostream>

using namespace std;

int main() {
    int data = 3;
    int *p = &data;

    cout << "Value of data: " << data << endl;
    cout << "Address of data: " << &data << endl;

    cout << "Value of p: " << p << endl;
    cout << "Address of p: " << &p << endl;
    cout << "Value of data pointed by p: " << *p << endl;
    
    *p = 5;

    cout << "Value of data: " << data << endl;
    cout << "Value of data pointed by p: " << *p << endl;

    return 0;
}