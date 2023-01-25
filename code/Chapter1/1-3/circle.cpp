#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    const double PI = 3.14159;
    double r;
    double area;

    cout << "Radius: ";
    cin >> r;

    area = PI * pow(r, 2);
    cout << "Area = " << fixed << setprecision(2) << area << endl;
    
    return 0;
}