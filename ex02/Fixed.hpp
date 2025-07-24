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
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;
        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
        static Fixed& max(Fixed& x1, Fixed& x2);
        static Fixed& min(Fixed& x1, Fixed& x2);
        static const Fixed& max(const Fixed& x1, const Fixed& x2);
        static const Fixed& min(const Fixed& x1, const Fixed& x2);
    private:
        int _value;
        static const int _fracBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif