#include "WrongCat.hpp"

WrongCat::WrongCat() {
  type = "WrongCat";
  std::cout << "WrongCat: Default Constuctor Called" << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat: Destructor Called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongcat) : WrongAnimal(wrongcat) {
  type = wrongcat.type;
  std::cout << "WrongCat: Copy Constuctor Called" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat& wrongcat) {
  type = wrongcat.type;
  std::cout << "WrongCat: Operator Called" << std::endl;
  return (*this);
}

void WrongCat::makeSound() const {
  std::cout << "WrongCat: Wrong Wrong Meow ~" << std::endl;
}
