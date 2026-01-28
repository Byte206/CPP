#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
private:
    int                 value;
    static const int    fractionalBits = 8;
public:
    Fixed(); // Default constructor
    Fixed(const Fixed& other); // Copy constructor
    Fixed(const int intValue); // Constructor from integer
    Fixed(const float floatValue); // Constructor from float
    Fixed& operator=(const Fixed& other); // Copy assignment operator
    ~Fixed(); // Destructor
    int getRawBits(void) const; // Getter for the raw fixed-point value
    void setRawBits(int const raw); // Setter for the raw fixed-point value
    float toFloat(void) const; // Convert to float
    int toInt(void) const; // Convert to integer

    //ex02
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

    Fixed& operator++();       // Prefix increment
    Fixed operator++(int);     // Postfix increment
    Fixed& operator--();       // Prefix decrement
    Fixed operator--(int);     // Postfix decrement

    //methods
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif

