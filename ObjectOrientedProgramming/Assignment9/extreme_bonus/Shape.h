#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include <cmath>

class Shape {
public:
    virtual std::string name() const = 0; 
    virtual double area() const = 0;      
    std::string to_string() const;
};

#endif