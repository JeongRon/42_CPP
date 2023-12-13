#include "Ice.hpp"

#include "ICharacter.hpp"

Ice::Ice() {
  this->setType("ice");
  std::cout << "Ice: Default Constructor Called" << std::endl;
}

Ice::~Ice() { std::cout << "Ice: Destructor Called" << std::endl; }

Ice::Ice(const Ice& ice) : AMateria(ice) {
  this->type = ice.type;
  std::cout << "Ice: Copy Called" << std::endl;
}

Ice& Ice::operator=(Ice& ice) {
  this->type = ice.type;
  std::cout << "Ice: Operator= Called" << std::endl;
  return (*this);
}

AMateria* Ice::clone() const {
  AMateria* tmp = new Ice(*this);
  return (tmp);
}

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}