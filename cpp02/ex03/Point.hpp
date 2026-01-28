#include <iostream>
#include <string>
#include "Fixed.hpp"
#ifndef POINT_HPP
#define POINT_HPP


class Point {
private:
    const Fixed x;
    const Fixed y;
public:
    Point(); // Default constructor
    Point(const float xValue, const float yValue); // Parameterized constructor
    Point(const Point& other); // Copy constructor

    Point& operator=(const Point& other); // Copy assignment operator
    ~Point(); // Destructor

    Fixed getX() const;
    Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif