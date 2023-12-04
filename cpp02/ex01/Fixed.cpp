#include "Fixed.hpp"

// default constructor
Fixed::Fixed() {
  std::cout << "Default constructor called" << std::endl;
  rawBits = 0;
}

Fixed::Fixed(int num) {
  std::cout << "Int constructor called" << std::endl;
  rawBits = num << FRACTIONAL_BIT;
}

Fixed::Fixed(float num) {
  std::cout << "Float constructor called" << std::endl;
  rawBits = roundf(num * (1 << FRACTIONAL_BIT));
}

// destructor
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

// copy constructor
Fixed::Fixed(const Fixed& fixed) {
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

// copy assignment operator overload
Fixed& Fixed::operator=(const Fixed& fixed) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &fixed) rawBits = fixed.getRawBits();
  return *this;
}

// member function
float Fixed::toFloat(void) const {
  return ((float)rawBits / (1 << FRACTIONAL_BIT));
}

int Fixed::toInt(void) const { return (rawBits >> FRACTIONAL_BIT); }

int Fixed::getRawBits(void) const {
  // std::cout << "getRawBits member function called" << std::endl;
  return rawBits;
};

void Fixed::setRawBits(int const raw) { rawBits = raw; };

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
  out << fixed.toFloat();
  return (out);
}