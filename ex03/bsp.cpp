#include "Point.hpp"

Fixed area(Point const p1, Point const p2, Point const p3) {
    const Fixed& x1 = p1.get_x();
    const Fixed& y1 = p1.get_y();
    const Fixed& x2 = p2.get_x();
    const Fixed& y2 = p2.get_y();
    const Fixed& x3 = p3.get_x();
    const Fixed& y3 = p3.get_y();
    
    Fixed twoA = Fixed::abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
    return twoA / Fixed(2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed A = area(a, b, c);
    Fixed A1 = area(point, b, c);
    Fixed A2 = area(a, point, c);
    Fixed A3 = area(a, b, point);

    if (A1 == 0 || A2 == 0 || A3 == 0)
        return false;

    return (A == (A1 + A2 + A3));
}
