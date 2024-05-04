#include "Circle.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Circle::Circle(double r) : _radius(r) {}

std::string Circle::name() const {
    return "Circle of radius " + std::to_string(_radius);
}

double Circle::area() const {
    return M_PI * _radius * _radius;
}
