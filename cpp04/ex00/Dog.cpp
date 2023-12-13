#include "Dog.hpp"

Dog::Dog() {
  type = "Dog";
  std::cout << "Dog: Default Constuctor Called" << std::endl;
}

Dog::~Dog() { std::cout << "Dog: Destructor Called" << std::endl; }

Dog::Dog(const Dog& dog) : Animal(dog) {
  type = dog.type;
  std::cout << "Dog: Copy Constuctor Called" << std::endl;
}

Dog& Dog::operator=(Dog& dog) {
  type = dog.type;
  std::cout << "Dog: Operator Called" << std::endl;
  return (*this);
}

void Dog::makeSound() const { std::cout << "Dog: Bark, Bark !" << std::endl; }
