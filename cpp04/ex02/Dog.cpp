#include "Dog.hpp"

Dog::Dog() {
  type = "Dog";
  brain = new Brain();
  std::cout << "Dog: Default Constuctor Called" << std::endl;
}

Dog::~Dog() {
  delete brain;
  std::cout << "Dog: Destructor Called" << std::endl;
}

Dog::Dog(const Dog& dog) {
  type = dog.type;

  delete brain;
  brain = new Brain(*dog.getBrain());

  std::cout << "Dog: Copy Constuctor Called" << std::endl;
}

Dog& Dog::operator=(Dog& dog) {
  type = dog.type;

  delete brain;
  brain = new Brain(*dog.getBrain());

  std::cout << "Dog: Operator Called" << std::endl;
  return (*this);
}

Brain* Dog::getBrain() const { return (this->brain); }

void Dog::makeSound() const { std::cout << "Dog: Bark, Bark !" << std::endl; }
