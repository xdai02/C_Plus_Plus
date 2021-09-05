#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "shape.h"

class Circle : public Shape {
public:
    Circle(double raidus = 0);
    virtual double getArea() override;

private:
    double radius;
};

#endif