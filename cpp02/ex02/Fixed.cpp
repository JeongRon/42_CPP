#include "Fixed.hpp"

// default constructor
Fixed::Fixed() {
  // std::cout << "Default constructor called" << std::endl;
  rawBits = 0;
}

Fixed::Fixed(int num) {
  // std::cout << "Int constructor called" << std::endl;
  rawBits = num << FRACTIONAL_BIT;
}

Fixed::Fixed(float num) {
  // std::cout << "Float constructor called" << std::endl;
  rawBits = roundf(num * (1 << FRACTIONAL_BIT));
}

// destructor
Fixed::~Fixed() {
  // std::cout << "Destructor called" << std::endl;
}

// copy constructor
Fixed::Fixed(const Fixed& fixed) {
  // std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

// copy assignment operator overload
Fixed& Fixed::operator=(const Fixed& fixed) {
  // std::cout << "Copy assignment operator called" << std::endl;
  if (this != &fixed) rawBits = fixed.getRawBits();
  return *this;
}

// member function
Fixed Fixed::operator+(const Fixed& other) const {
  Fixed tmp(this->toFloat() + other.toFloat());
  return (tmp);
}
Fixed Fixed::operator-(const Fixed& other) const {
  Fixed tmp(this->toFloat() - other.toFloat());
  return (tmp);
}
Fixed Fixed::operator*(const Fixed& other) const {
  Fixed tmp(this->toFloat() * other.toFloat());
  return (tmp);
}
Fixed Fixed::operator/(const Fixed& other) const {
  Fixed tmp(this->toFloat() / other.toFloat());
  return (tmp);
}

Fixed& Fixed::operator++(void) {
  this->rawBits++;
  return (*this);
}
const Fixed Fixed::operator++(int) {
  const Fixed tmp(*this);
  this->rawBits++;
  return (tmp);
}
Fixed& Fixed::operator--(void) {
  this->rawBits--;
  return (*this);
}
const Fixed Fixed::operator--(int) {
  const Fixed tmp(*this);
  this->rawBits--;
  return (tmp);
}

bool Fixed::operator>(const Fixed& other) const {
  return (this->getRawBits() > other.getRawBits());
}
bool Fixed::operator<(const Fixed& other) const {
  return (this->getRawBits() < other.getRawBits());
}
bool Fixed::operator>=(const Fixed& other) const {
  return (this->getRawBits() >= other.getRawBits());
}
bool Fixed::operator<=(const Fixed& other) const {
  return (this->getRawBits() <= other.getRawBits());
}
bool Fixed::operator==(const Fixed& other) const {
  return (this->getRawBits() == other.getRawBits());
}
bool Fixed::operator!=(const Fixed& other) const {
  return (this->getRawBits() != other.getRawBits());
}

Fixed& Fixed::min(Fixed& fix1, Fixed& fix2) {
  if (fix1 <= fix2)
    return (fix1);
  else
    return (fix2);
}
const Fixed& Fixed::min(Fixed const& fix1, Fixed const& fix2) {
  if (fix1 <= fix2)
    return (fix1);
  else
    return (fix2);
}
Fixed& Fixed::max(Fixed& fix1, Fixed& fix2) {
  if (fix1 >= fix2)
    return (fix1);
  else
    return (fix2);
}
const Fixed& Fixed::max(Fixed const& fix1, Fixed const& fix2) {
  if (fix1 >= fix2)
    return (fix1);
  else
    return (fix2);
}

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