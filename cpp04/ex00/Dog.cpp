#include "Dog.hpp"

Dog::Dog() {
  type = "Dog";
  std::cout << "Dog: Default Constuctor Called" << std::endl;
}

Dog::~Dog() { std::cout << "Dog: Destructor Called" << std::endl; }

Dog::Dog(const Dog& animal) {
  type = animal.type;
  std::cout << "Dog: Copy Constuctor Called" << std::endl;
}

Dog& Dog::operator=(Dog& animal) {
  type = animal.type;
  std::cout << "Dog: Operator Called" << std::endl;
  return (*this);
}

void Dog::makeSound() const { std::cout << "Dog: Bark, Bark !" << std::endl; }
