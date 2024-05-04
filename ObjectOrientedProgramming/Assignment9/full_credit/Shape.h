#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include <cmath>

class Shape {
    public:
        virtual std::string name() const;
        virtual double area() const;
        std::string to_string() const;
};

#endif