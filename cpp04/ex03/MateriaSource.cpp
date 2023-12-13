#include "MateriaSource.hpp"

#include "AMateria.hpp"

MateriaSource::MateriaSource() : inventory() {
  std::cout << "MateriaSource: Default Constructor Called" << std::endl;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; i++) {
    delete inventory[i];
    inventory[i] = NULL;
  }
  std::cout << "MateriaSource: Destructor Called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& source) {
  for (int i = 0; i < 4; i++) {
    delete inventory[i];
    inventory[i] = NULL;
  }
  for (int i = 0; i < 4; i++) {
    inventory[i] = source.inventory[i]->clone();
  }
  std::cout << "MateriaSource: Copy Called" << std::endl;
}

MateriaSource& MateriaSource::operator=(MateriaSource& source) {
  for (int i = 0; i < 4; i++) {
    delete inventory[i];
    inventory[i] = NULL;
  }
  for (int i = 0; i < 4; i++) {
    inventory[i] = source.inventory[i]->clone();
  }
  std::cout << "MateriaSource: Operator= Called" << std::endl;
  return (*this);
}

void MateriaSource::learnMateria(AMateria* m) {
  if (!m) {
    std::cout << "MateriaSource learnMateria ERROR: Invalid materia !"
              << std::endl;
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (inventory[i] == NULL) {
      inventory[i] = m;
      std::cout << "MateriaSource learnMateria SUCCESS: Learned Materia in "
                << i << " index" << std::endl;
      return;
    }
  }

  std::cout << "MateriaSource learnMateria ERROR: Inventory Full !"
            << std::endl;
  delete m;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
  for (int i = 0; i < 4; i++) {
    if (inventory[i]) {
      if (inventory[i]->getType() == type) {
        std::cout << "MateriaSource createMateria SUCCESS" << std::endl;
        return (inventory[i]->clone());
      }
    }
  }
  std::cout << "MateriaSource createMateria ERROR: Inventory " << type
            << "type Nothing !" << std::endl;
  return (NULL);
}