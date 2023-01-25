#include <iostream>

using namespace std;

int main() {
    char s1[32] = {0};
    char s2[32] = {0};

    cout << "Enter string 1: ";
    cin.getline(s1, 32);
    cout << "Enter string 2: ";
    cin.getline(s2, 32);

    int i = 0;
    while (s1[i] != '\0') {
        i++;
    }

    int j = 0;
    while (s2[j] != '\0') {
        s1[i++] = s2[j++];
    }

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;

    return 0;
}