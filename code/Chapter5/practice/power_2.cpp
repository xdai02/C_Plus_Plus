#include <iostream>

using namespace std;

int power_2(int x) {
    if (x == 0) {
        return 1;
    }
    return 2 * power_2(x - 1);
}

int main() {
    int x;
    cout << "Enter x: ";
    cin >> x;

    cout << power_2(x) << endl;
    return 0;
}