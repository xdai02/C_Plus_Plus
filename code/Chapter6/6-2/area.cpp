#include <iostream>
#include <iomanip>
#include "geometry.h"

using namespace std;

int main() {
    cout << "Area of circle: "
         << fixed << setprecision(2) << circle_area(5) << endl;
    
    cout << "Area of triangle: "
         << fixed << setprecision(2) << triangle_area(5, 10) << endl;
    
    return 0;
}