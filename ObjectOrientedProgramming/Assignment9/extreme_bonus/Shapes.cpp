#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Shape*> shapes;

    Rectangle rectangle(3.0, 4.0);
    Circle circle(2.0);

    shapes.push_back(&rectangle);
    shapes.push_back(&circle);

    for (const Shape* shape : shapes) {
        std::cout << shape->to_string() << std::endl;
    }

    return 0;
}