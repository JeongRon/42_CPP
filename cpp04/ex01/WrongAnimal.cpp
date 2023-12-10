#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
  type = "Wrong";
  std::cout << "WrongAnimal: Default Constuctor Called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal: Destructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& animal) {
  type = animal.type;
  std::cout << "WrongAnimal: Copy Constuctor Called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal& animal) {
  type = animal.type;
  std::cout << "WrongAnimal: Operator Called" << std::endl;
  return (*this);
}

std::string WrongAnimal::getType() const { return type; }

void WrongAnimal::makeSound() const {
  std::cout << "WrongAnimal: WrongAnimal Sound !" << std::endl;
}
