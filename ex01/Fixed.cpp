#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
};

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    _value = value << _fracBits;
};

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(value * pow(2, _fracBits));
};

Fixed& Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
};

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits(void) const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

float Fixed::toFloat(void) const {
    return 1.0 * _value / pow(2, _fracBits);
}

int Fixed::toInt(void) const {
    return _value / pow(2, _fracBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
