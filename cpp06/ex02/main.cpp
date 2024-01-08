#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base* generate(void) {
  std::srand(static_cast<unsigned>(std::time(NULL)));
  int randomFlag = std::rand() % 3;

  if (randomFlag == 0) {
    return new A();
  } else if (randomFlag == 1) {
    return new B();
  } else {
    return new C();
  }
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p)) std::cout << "Identify: A" << std::endl;
  if (dynamic_cast<B*>(p)) std::cout << "Identify: B" << std::endl;
  if (dynamic_cast<C*>(p)) std::cout << "Identify: C" << std::endl;
}

void identify(Base& p) {
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "Identify(R): A" << std::endl;
  } catch (std::exception& e) {
    try {
      (void)dynamic_cast<B&>(p);
      std::cout << "Identify(R): B" << std::endl;
    } catch (std::exception& e) {
      try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Identify(R): C" << std::endl;
      } catch (std::exception& e) {
        std::cout << "Identify(R): ERROR" << std::endl;
      }
    }
  }
}

int main(void) {
  std::cout << "--------------------" << std::endl;
  Base* p = generate();

  identify(p);

  Base& ref_p = *p;
  identify(ref_p);

  delete p;
  std::cout << "--------------------" << std::endl;
  return 0;
}