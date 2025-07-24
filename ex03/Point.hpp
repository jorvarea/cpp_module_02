#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
    public:
        Point();
        Point(const float x, const float y);
        Point& operator=(const Point& other);
        ~Point();
    private:
        const Fixed _x;
        const Fixed _y;
};

#endif