#include <iostream>
#include "mystring.h"

using namespace std;

int main() {
    char s1[16] = "Hello";
    char s2[16] = "World!";
    char *result = NULL;

    int s1_len = mystrlen(s1);
    cout << "mystrlen(\"" << s1 << "\") = " << s1_len << endl;

    result = mystrcpy(s1, s2);
    cout << "mystrcpy(\"" << s1 << "\", \"" << s2 << "\") = " << result << endl;

    result = mystrcat(s1, s2);
    cout << "mystrcat(\"" << s1 << "\", \"" << s2 << "\") = " << result << endl;

    cout << "mystrcmp(\"" << s1 << "\", \"" << s2 << "\") = " << mystrcmp(s1, s2) << endl;

    return 0;
}