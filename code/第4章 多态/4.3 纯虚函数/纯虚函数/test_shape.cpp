#include <iostream>
#include "rectangle.h"
#include "circle.h"

using namespace std;

int main() {
    Rectangle rectangle(7, 5);
    Circle circle(6);
    cout << "rectangle: " << rectangle.getArea() << endl;
    cout << "circle: " << circle.getArea() << endl;
    return 0;
}