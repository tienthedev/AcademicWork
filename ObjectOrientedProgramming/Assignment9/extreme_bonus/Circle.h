#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
using namespace std;

class Circle : public Shape {
private:
    double _radius;

public:
    Circle(double r);
    string name() const override;
    double area() const override;
};

#endif