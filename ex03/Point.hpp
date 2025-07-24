#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point& point);
        Point& operator=(const Point& other);
        ~Point();

        const Fixed& get_x(void) const;
        const Fixed& get_y(void) const;
    private:
        const Fixed _x;
        const Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif