#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    public:
        Fixed();
        Fixed(const Fixed& fixed);
        Fixed(const int value);
        Fixed(const float value);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
    private:
        int _value;
        static const int _fracBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif