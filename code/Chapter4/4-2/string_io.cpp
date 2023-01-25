#include <iostream>

using namespace std;

int main() {
    char str1[32];
    cout << "Enter string 1: ";
    cin.getline(str1, 32);
    cout << str1 << endl;

    char str2[32];
    cout << "Enter string 2: ";
    cin >> str2;
    cout << str2 << endl;

    return 0;
}