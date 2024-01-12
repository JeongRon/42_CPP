#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <iostream>

class ScalarConverter {
 private:
  /* Block */
  ScalarConverter();
  ~ScalarConverter();
  ScalarConverter(ScalarConverter const &other);
  ScalarConverter &operator=(ScalarConverter const &other);

 public:
  /* Static Method */
  static void convert(std::string const &input);
};

#endif