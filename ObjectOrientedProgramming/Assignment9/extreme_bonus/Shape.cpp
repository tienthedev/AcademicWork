#include "Shape.h"
#include <iostream>

std::string Shape::to_string() const {
    return name() + " with area " + std::to_string(area());
}