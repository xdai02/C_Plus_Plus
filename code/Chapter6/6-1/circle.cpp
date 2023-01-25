#include <iostream>
#define PI 3.14159

using namespace std;

double perimeter(double r) {
    return 2 * PI * r;
}

double area(double r) {
    return PI * r * r;
}

int main() {
    double radius;
    cout << "Enter radius: ";
    cin >> radius;

    cout << "Perimeter: " << perimeter(radius) << endl;
    cout << "Area: " << area(radius) << endl;

    return 0;
}