#include "Cure.hpp"

#include "ICharacter.hpp"

Cure::Cure() {
  this->setType("cure");
  std::cout << "Cure: Default Constructor Called" << std::endl;
}

Cure::~Cure() { std::cout << "Cure: Destructor Called" << std::endl; }

Cure::Cure(const Cure& cure) : AMateria(cure) {
  this->type = cure.type;
  std::cout << "Cure: Copy Called" << std::endl;
}

Cure& Cure::operator=(Cure& cure) {
  this->type = cure.type;
  std::cout << "Cure: Operator= Called" << std::endl;
  return (*this);
}

AMateria* Cure::clone() const {
  AMateria* tmp = new Cure(*this);
  return (tmp);
}

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}