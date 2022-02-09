#include <iostream>
#include <string>

using namespace std;

template <typename T>
inline T getMax(const T& val1, const T& val2) {
    return val1 > val2 ? val1 : val2;
}

int main() {
    int iVal1 = 28;
    int iVal2 = 92;
    cout << getMax(iVal1, iVal2) << endl;

    double dVal1 = 3.14;
    double dVal2 = 3.71;
    cout << getMax(dVal1, dVal2) << endl;

    string sVal1 = "hello";
    string sVal2 = "world";
    cout << getMax(sVal1, sVal2) << endl;
    return 0;
}
