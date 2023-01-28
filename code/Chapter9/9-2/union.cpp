#include <iostream>

using namespace std;

union Value {
    int int_data;
    char char_data;
};

int main() {
    union Value val;

    val.char_data = 'A';
    cout << "val.int_data = " << val.int_data << endl;

    val.int_data = 97;
    cout << "val.char_data = " << val.char_data << endl;

    return 0;
}