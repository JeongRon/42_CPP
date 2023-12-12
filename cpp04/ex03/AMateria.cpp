#include "AMateria.hpp"

AMateria::AMateria() {
  std::cout << "AMateria : Default Constructor Called" << std::endl;
};

AMateria::AMateria(std::string const& type) {
  this->type = type;
  std::cout << "AMateria : Constructor " << type << " Called" << std::endl;
}

AMateria::~AMateria() {
  std::cout << "AMateria : Destructor Called" << std::endl;
};

AMateria::AMateria(const AMateria& materia) {
  this->type = materia.type;
  std::cout << "AMateria : Copy Called" << std::endl;
}

AMateria& AMateria::operator=(AMateria& materia) {
  this->type = materia.type;
  std::cout << "AMateria : Operator= Called" << std::endl;
  return (*this);
}

std::string const& AMateria::getType() const { return (type); }

void AMateria::setType(std::string type) { this->type = type; }

void AMateria::use(ICharacter& target) {
  std::cout << "AMateria : " << target.getName() << std::endl;
}