#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  try {
    std::cout << "-----------------------------" << std::endl;
    Bureaucrat employee("employee", 100);
    std::cout << employee << std::endl;
    std::cout << "----------------------------" << std::endl;
    Form report1("report1", 120, 120);
    std::cout << report1 << std::endl;
    std::cout << "----------------------------" << std::endl;
    employee.signForm(report1);
    std::cout << report1 << std::endl;
    std::cout << "----------------------------" << std::endl;
    Form report2("report2", 50, 50);
    std::cout << report2 << std::endl;
    std::cout << "----------------------------" << std::endl;
    employee.signForm(report2);
    std::cout << report2 << std::endl;
    std::cout << "----------------------------" << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}