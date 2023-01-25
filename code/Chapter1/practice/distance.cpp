#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double x1, y1;
    double x2, y2;

    cout << "Enter point 1: ";
    cin >> x1 >> y1;
    cout << "Enter point 2: ";
    cin >> x2 >> y2;

    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    cout << "Distance = " << fixed << setprecision(2) << distance << endl;

    return 0;
}