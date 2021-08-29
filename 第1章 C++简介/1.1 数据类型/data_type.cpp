#include <iostream>
#include <limits>

using namespace std;

int main() {
    cout << "int" << endl;
    cout << "size: " << sizeof(int) << endl;
    cout << "min: " << numeric_limits<int>::min() << endl;
    cout << "max: " << numeric_limits<int>::max() << endl;
    cout << "---------------------------------" << endl;
    cout << "short" << endl;
    cout << "size: " << sizeof(short) << endl;
    cout << "min: " << numeric_limits<short>::min() << endl;
    cout << "max: " << numeric_limits<short>::max() << endl;
    cout << "---------------------------------" << endl;
    cout << "long" << endl;
    cout << "size: " << sizeof(long) << endl;
    cout << "min: " << numeric_limits<long>::min() << endl;
    cout << "max: " << numeric_limits<long>::max() << endl;
    cout << "---------------------------------" << endl;
    cout << "long long" << endl;
    cout << "size: " << sizeof(long long) << endl;
    cout << "min: " << numeric_limits<long long>::min() << endl;
    cout << "max: " << numeric_limits<long long>::max() << endl;
    cout << "---------------------------------" << endl;
    cout << "float" << endl;
    cout << "size: " << sizeof(float) << endl;
    cout << "min: " << numeric_limits<float>::min() << endl;
    cout << "max: " << numeric_limits<float>::max() << endl;
    cout << "---------------------------------" << endl;
    cout << "double" << endl;
    cout << "size: " << sizeof(double) << endl;
    cout << "min: " << numeric_limits<double>::min() << endl;
    cout << "max: " << numeric_limits<double>::max() << endl;
    cout << "---------------------------------" << endl;
    cout << "char" << endl;
    cout << "size: " << sizeof(char) << endl;
    cout << "---------------------------------" << endl;
    cout << "bool" << endl;
    cout << "size: " << sizeof(bool) << endl;
    cout << "min: " << numeric_limits<bool>::min() << endl;
    cout << "max: " << numeric_limits<bool>::max() << endl;
    cout << "---------------------------------" << endl;

    return 0;
}