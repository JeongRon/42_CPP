#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <iomanip>
#include <iostream>

class Calculator {
 private:
  bool isConvertToDouble;
  double doubleNum;
  int fractionalLength;

 public:
  /* OCF */
  Calculator();
  ~Calculator();
  Calculator(Calculator const &other);
  Calculator &operator=(Calculator const &other);

  /* Getter */
  bool getIsConvertToDouble();
  double getDoubleNum();
  int getFractionalLength();

  /* Setter */
  void setIsConvertToDouble(bool setBool);
  void setDoubleNum(double setDouble);
  void setFractionalLength(int length);

  /* Check */
  void checkString(std::string const &input);
  void checkFractionalLength(std::string const &input, double value);

  /* Convert */
  void convertToChar();
  void convertToInt();
  void convertToFloat();
  void convertToDouble();
};

#endif