#include "Calculator.hpp"

/* OCF */
Calculator::Calculator()
    : isConvertToDouble(false), doubleNum(0), fractionalLength(0) {}

Calculator::~Calculator() {}

Calculator::Calculator(Calculator const &other) { (void)other; }

Calculator &Calculator::operator=(Calculator const &other) {
  (void)other;
  return (*this);
}

/* Getter */
bool Calculator::getIsConvertToDouble() { return isConvertToDouble; }

double Calculator::getDoubleNum() { return doubleNum; }

int Calculator::getFractionalLength() { return fractionalLength; }

/* Setter */
void Calculator::setIsConvertToDouble(bool setBool) {
  isConvertToDouble = setBool;
}

void Calculator::setDoubleNum(double setDouble) { doubleNum = setDouble; }

void Calculator::setFractionalLength(int length) { fractionalLength = length; }

/* Check */
void Calculator::checkString(std::string const &input) {
  if (input.length() == 1) {
    char c = static_cast<char>(input[0]);
    int asciiNum = static_cast<int>(c);
    setDoubleNum(asciiNum);
    this->setIsConvertToDouble(true);
  } else {
    this->setIsConvertToDouble(false);
  }
}

void Calculator::checkFractionalLength(std::string const &input, double value) {
  if (isnan(value) || isinf(value)) {
    setFractionalLength(-1);
    return;
  }

  float f = static_cast<float>(value);
  if (isnan(f) || isinf(f)) {
    setFractionalLength(-2);
    return;
  }

  int changeFlag = false;
  int length = 0;
  for (int i = 0;; i++) {
    if (input[i] == '\0') break;

    if (changeFlag == false) {
      if (input[i] == '.') {
        changeFlag = true;
        continue;
      }
    } else {
      if ('0' <= input[i] && input[i] <= '9') length++;
    }
    setFractionalLength(length);
  }
}

/* Convert */
void Calculator::convertToChar() {
  double num = this->getDoubleNum();

  std::cout << "char: ";
  if (0 <= num && num <= 255) {
    unsigned char c = static_cast<unsigned char>(num);

    if (isprint(static_cast<int>(c)) == 0)
      std::cout << "Non Displayable" << std::endl;
    else
      std::cout << '\'' << c << '\'' << std::endl;
  } else {
    std::cout << "impossible" << std::endl;
  }
}

void Calculator::convertToInt() {
  double num = this->getDoubleNum();

  std::cout << "int: ";
  if (-2147483648 <= num && num <= 2147483647) {
    int i = static_cast<int>(num);

    std::cout << i << std::endl;
  } else {
    std::cout << "impossible" << std::endl;
  }
}
void Calculator::convertToFloat() {
  int fractionalLength = this->getFractionalLength();
  double num = this->getDoubleNum();
  float f = static_cast<float>(num);

  std::cout << "float: ";
  std::cout << std::fixed << std::setprecision(fractionalLength) << f;
  if (fractionalLength == 0) {
    std::cout << ".0";
  }
  std::cout << "f" << std::endl;
}

void Calculator::convertToDouble() {
  int fractionalLength = this->getFractionalLength();
  double d = this->getDoubleNum();

  std::cout << "double: ";
  std::cout << std::fixed << std::setprecision(fractionalLength) << d;
  if (fractionalLength == 0) {
    std::cout << ".0";
  }
  std::cout << std::endl;
}