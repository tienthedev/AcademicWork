#include "Rectangle.h"

Rectangle::Rectangle(double w, double h) : _width(w), _height(h) {}

std::string Rectangle::name() const {
    return std::to_string(_width) + "x" + std::to_string(_height) + " Rectangle";
}

double Rectangle::area() const {
    return _width * _height;
}
