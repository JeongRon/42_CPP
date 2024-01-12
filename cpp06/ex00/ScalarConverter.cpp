#include "ScalarConverter.hpp"

#include "Calculator.hpp"

/* Block */
ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &other) { (void)other; }

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
  (void)other;
  return *this;
}

/* Static Method */
void ScalarConverter::convert(std::string const &input) {
  if (input.length() == 0) {
    std::cout << "Please Input One Literal" << std::endl;
    return;
  }

  Calculator calculator = Calculator();
  char *endptr = NULL;
  double value = std::strtod(input.c_str(), &endptr);

  if (*endptr == '\0') {
    calculator.setDoubleNum(value);
    calculator.setIsConvertToDouble(true);
  } else {
    if (*endptr++ == 'f' && *endptr == '\0') {
      calculator.setDoubleNum(value);
      calculator.setIsConvertToDouble(true);
    } else
      calculator.checkString(input);
  }

  if (calculator.getIsConvertToDouble() == true) {
    // Success ConvertToDouble
    calculator.checkFractionalLength(input, value);
    calculator.convertToChar();
    calculator.convertToInt();
    calculator.convertToFloat();
    calculator.convertToDouble();
  } else {
    // Fail ConvertToDouble
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
  }
}
