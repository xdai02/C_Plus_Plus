#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double side1, side2, side3;
    cout << "Enter three sides of a triangle: ";
    cin >> side1 >> side2 >> side3;

    if(side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1)
    {
        cout << "Invalid" << endl;
    }
    else
    {
        double p = (side1 + side2 + side3) / 2;
        double area = sqrt(p * (p - side1) * (p - side2) * (p - side3));
        cout << "Area = " << fixed << setprecision(2) << area << endl;
    }

    return 0;
}