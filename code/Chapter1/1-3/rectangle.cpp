#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int length = 10;
    int width = 5;
    double area = length * width;

    cout << "Area = " << length << " * " << width << " = "
         << fixed << setprecision(2) << area << endl;
    return 0;
}