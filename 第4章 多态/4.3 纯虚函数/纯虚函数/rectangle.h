#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "shape.h"

class Rectangle : public Shape {
public:
    Rectangle(double length = 0, double width = 0);
    virtual double getArea() override;

private:
    double length;
    double width;
};

#endif