#include "RPN.hpp"

/* OCF */
RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) { this->numberStack = other.numberStack; }

RPN& RPN::operator=(const RPN& other) {
  if (this != &other) {
    this->numberStack = other.numberStack;
  }
  return *this;
}

/* Member Function*/
void RPN::executeRpn(std::string& str) {
  for (std::size_t i = 0; i < str.length(); i++) {
    if ('0' <= str[i] && str[i] <= '9')
      numberStack.push(str[i] - 48);
    else if (str[i] == ' ')
      continue;
    else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
      if (numberStack.size() <= 1)
        throw std::runtime_error("Error: Invalid Expression");

      double b = numberStack.top();
      numberStack.pop();

      double a = numberStack.top();
      numberStack.pop();

      double result = oper(a, str[i], b);
      numberStack.push(result);
    } else
      throw std::runtime_error("Error: Invalid Character");
  }

  if (numberStack.size() != 1)
    throw std::runtime_error("Error: Invalid Expression");
  std::cout << numberStack.top() << std::endl;
}

double oper(double a, char op, double b) {
  switch (op) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      if (b == 0) throw std::runtime_error("Error: Division by zero");
      return a / b;
    default:
      throw std::runtime_error("Error: Invalid Operator");
  }
}
