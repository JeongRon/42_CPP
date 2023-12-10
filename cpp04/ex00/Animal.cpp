#include "Animal.hpp"

Animal::Animal() {
  type = "Nothing";
  std::cout << "Animal: Default Constuctor Called" << std::endl;
}

Animal::~Animal() { std::cout << "Animal: Destructor Called" << std::endl; }

Animal::Animal(const Animal& animal) {
  type = animal.type;
  std::cout << "Animal: Copy Constuctor Called" << std::endl;
}

Animal& Animal::operator=(Animal& animal) {
  type = animal.type;
  std::cout << "Animal: Operator Called" << std::endl;
  return (*this);
}

std::string Animal::getType() const { return type; }

void Animal::makeSound() const {
  std::cout << "Animal: No Type, No Sound !" << std::endl;
}
