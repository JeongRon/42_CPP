#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
 private:
  static const int FRACTIONAL_BIT = 8;
  int rawBits;

 public:
  Fixed();                               // default constructor
  ~Fixed();                              // destructor
  Fixed(const Fixed& fixed);             // copy constructor
  Fixed& operator=(const Fixed& fixed);  // copy assignment operator overload

  // memeber function
  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif