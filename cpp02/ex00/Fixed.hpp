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
    Fixed& operator=(const Fixed& other); // Copy assignment operator
    ~Fixed(); // Destructor
    int getRawBits(void) const; // Getter for the raw fixed-point value
    void setRawBits(int const raw); // Setter for the raw fixed-point value
};
#endif

