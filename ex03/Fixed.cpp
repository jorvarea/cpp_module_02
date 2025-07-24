#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0) {};

Fixed::Fixed(const Fixed &other) {
    *this = other;
};

Fixed::Fixed(const int value) {
    _value = value << _fracBits;
};

Fixed::Fixed(const float value) {
    _value = roundf(value * (1 << _fracBits));
};

Fixed& Fixed::operator=(const Fixed &other) {
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
};

bool Fixed::operator>(const Fixed& other) const {
    return this->_value > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const {
    return this->_value < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->_value >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->_value <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const {
    return this->_value == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->_value != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_value + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_value - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_value * other.getRawBits() / (1 << _fracBits));
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    result.setRawBits(1.0 * this->_value / other.getRawBits() * (1 << _fracBits));
    return result;
}

Fixed& Fixed::operator++(void) {
    this->_value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp = *this;
    this->_value++;
    return tmp;
}

Fixed& Fixed::operator--(void) {
    this->_value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp = *this;
    this->_value--;
    return tmp;
}

Fixed::~Fixed(){};

int Fixed::getRawBits(void) const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

float Fixed::toFloat(void) const {
    return 1.0 * _value / (1 << _fracBits);
}

int Fixed::toInt(void) const {
    return _value / (1 << _fracBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

Fixed& Fixed::max(Fixed& x1, Fixed& x2) {
    if (x1 < x2)
        return x2;
    else
        return x1;
}

const Fixed& Fixed::max(const Fixed& x1, const Fixed& x2) {
    if (x1 < x2)
        return x2;
    else
        return x1;
}

Fixed& Fixed::min(Fixed& x1, Fixed& x2) {
    if (x1 < x2)
        return x1;
    else
        return x2;
}

const Fixed& Fixed::min(const Fixed& x1, const Fixed& x2) {
    if (x1 < x2)
        return x1;
    else
        return x2;
}
