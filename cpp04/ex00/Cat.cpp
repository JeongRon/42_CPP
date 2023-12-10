#include "Cat.hpp"

Cat::Cat() {
  type = "Cat";
  std::cout << "Cat: Default Constuctor Called" << std::endl;
}

Cat::~Cat() { std::cout << "Cat: Destructor Called" << std::endl; }

Cat::Cat(const Cat& animal) {
  type = animal.type;
  std::cout << "Cat: Copy Constuctor Called" << std::endl;
}

Cat& Cat::operator=(Cat& animal) {
  type = animal.type;
  std::cout << "Cat: Operator Called" << std::endl;
  return (*this);
}

void Cat::makeSound() const { std::cout << "Cat: Meow, Meow ~" << std::endl; }
