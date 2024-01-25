#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
 private:
  std::stack<double> numberStack;

 public:
  /* OCF */
  RPN();
  ~RPN();
  RPN(const RPN& other);
  RPN& operator=(const RPN& other);

  /* Member Function*/
  void executeRpn(std::string& str);
};

double oper(double a, char op, double b);

#endif