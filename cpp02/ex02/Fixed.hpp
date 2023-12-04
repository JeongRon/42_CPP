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
  Fixed operator+(const Fixed& other) const;
  Fixed operator-(const Fixed& other) const;
  Fixed operator*(const Fixed& other) const;
  Fixed operator/(const Fixed& other) const;

  bool operator>(const Fixed& other) const;
  bool operator<(const Fixed& other) const;
  bool operator>=(const Fixed& other) const;
  bool operator<=(const Fixed& other) const;
  bool operator==(const Fixed& other) const;
  bool operator!=(const Fixed& other) const;

  Fixed& operator++(void);
  const Fixed operator++(int);
  Fixed& operator--(void);
  const Fixed operator--(int);

  static Fixed& min(Fixed& fix1, Fixed& fix2);
  static const Fixed& min(Fixed const& fix1, Fixed const& fix2);
  static Fixed& max(Fixed& fix1, Fixed& fix2);
  static const Fixed& max(Fixed const& fix1, Fixed const& fix2);

  float toFloat(void) const;
  int toInt(void) const;

  int getRawBits(void) const;
  void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif