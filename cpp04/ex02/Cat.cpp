#include "Cat.hpp"

Cat::Cat() {
  type = "Cat";
  brain = new Brain();
  std::cout << "Cat: Default Constuctor Called" << std::endl;
}

Cat::~Cat() {
  delete brain;
  brain = NULL;
  std::cout << "Cat: Destructor Called" << std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat) {
  type = cat.type;

  delete brain;
  brain = NULL;
  brain = new Brain(*cat.getBrain());

  std::cout << "Cat: Copy Constuctor Called" << std::endl;
}

Cat& Cat::operator=(Cat& cat) {
  type = cat.type;

  delete brain;
  brain = NULL;
  brain = new Brain(*cat.getBrain());

  std::cout << "Cat: Operator Called" << std::endl;
  return (*this);
}

Brain* Cat::getBrain() const { return (brain); }

void Cat::makeSound() const { std::cout << "Cat: Meow, Meow ~" << std::endl; }
