#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
 private:
  static const int FRACTIONAL_BIT = 8;
  int rawBits;

 public:
  Fixed();  // default constructor
  Fixed(int num);
  Fixed(float num);
  ~Fixed();                              // destructor
  Fixed(const Fixed& fixed);             // copy constructor
  Fixed& operator=(const Fixed& fixed);  // copy assignment operator overload

  // memeber function
  float toFloat(void) const;
  int toInt(void) const;

  int getRawBits(void) const;
  void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif