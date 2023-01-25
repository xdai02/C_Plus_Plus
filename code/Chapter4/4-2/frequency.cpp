#include <iostream>

using namespace std;

int main() {
    char str[32];
    char c;

    cout << "Enter a string: ";
    cin.getline(str, 32);
    cout << "Character to search: ";
    cin >> c;

    int cnt = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            cnt++;
        }
        i++;
    }

    cout << "'" << c << "' appears " << cnt << " times in \""
         << str << "\"." << endl;
         
    return 0;
}