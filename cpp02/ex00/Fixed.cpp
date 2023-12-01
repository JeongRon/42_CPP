#include "Fixed.hpp"

// default constructor
Fixed::Fixed() {
  std::cout << "Default constructor called" << std::endl;
  rawBits = 0;
}

// destructor
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

// copy constructor
Fixed::Fixed(const Fixed &fixed) {
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

// copy assignment operator overload
Fixed &Fixed::operator=(const Fixed &fixed) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &fixed) rawBits = fixed.getRawBits();
  return *this;
}

// member function
int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return rawBits;
};

void Fixed::setRawBits(int const raw) { rawBits = raw; };