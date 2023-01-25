#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double x;
    double y;

    cout << "Enter x: ";
    cin >> x;

    if(x < -2)
    {
        y = 0.5 * x + 3;
    }
    else if(x >= -2 && x <= 2)
    {
        y = 0;
    }
    else
    {
        y = pow(4, x);
    }

    cout << "y = " << fixed << setprecision(2) << y << endl;

    return 0;
}