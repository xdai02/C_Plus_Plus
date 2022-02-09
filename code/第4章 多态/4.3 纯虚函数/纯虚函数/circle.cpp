#include "circle.h"

Circle::Circle(double radius) : radius(radius) {}

double Circle::getArea() {
    return 3.14159 * radius * radius;
}