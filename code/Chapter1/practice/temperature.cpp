#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double C, F;

    cout << "Enter temperature in Celsius: ";
    cin >> C;

    F = 32 + C * 9 / 5;
    cout << "F = 32 + " << fixed << setprecision(2) << C << " * 9 / 5 = " << F << endl;

    return 0;
}