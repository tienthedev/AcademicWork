#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
    double _width;
    double _height;

public:
    Rectangle(double w, double h);
    std::string name() const override;
    double area() const override;
};

#endif
