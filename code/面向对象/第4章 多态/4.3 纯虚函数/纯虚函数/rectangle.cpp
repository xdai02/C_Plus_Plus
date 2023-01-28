#include "rectangle.h"

Rectangle::Rectangle(double length, double width)
	: length(length), width(width) {}

double Rectangle::getArea() {
    return length * width;
}