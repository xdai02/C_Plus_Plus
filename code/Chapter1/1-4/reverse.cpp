#include <iostream>

using namespace std;

int main()
{
    int num;
    int a, b, c;

    cout << "Enter a 3-digit integer: ";
    cin >> num;

    a = num / 100;
    b = num / 10 % 10;
    c = num % 10;

    cout << "Reversed: " << c*100 + b*10 + a << endl;
    return 0;
}