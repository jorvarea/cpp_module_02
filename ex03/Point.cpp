#include "Point.hpp"

Point::Point() : _x(0), _y(0) {};

Point::Point(const float x, const float y) : _x(x), _y(y) {};

Point::Point(const Point& point) : _x(point.get_x()), _y(point.get_y()) {};

Point& Point::operator=(const Point& other) {
    (void)other;
    std::cerr << "Constant attributes can't be changed" << std::endl;
    return *this;
}

const Fixed& Point::get_x(void) const {
    return _x;
}

const Fixed& Point::get_y(void) const {
    return _y;
}

Point::~Point() {};
