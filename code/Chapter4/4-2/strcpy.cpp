#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char s1[32] = "hello world";
    char s2[32] = "program";

    strcpy(s1, s2);
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    return 0;
}