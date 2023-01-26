#include <iostream>

using namespace std;

int main() {
    char str[] = "hello";
    char *s = str;
    char *t = s;

    s[0] = 'H';
    cout << "s = " << s << endl;
    cout << "t = " << t << endl;

    return 0;
}