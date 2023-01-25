#include <iostream>

using namespace std;

int main() {
    char str[32] = {0};
    cout << "Enter a string: ";
    cin.getline(str, 32);

    int i = 0;
    while (str[i] != '\0') {
        i++;
    }

    cout << "Length: " << i << endl;

    return 0;
}