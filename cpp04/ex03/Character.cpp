#include "Character.hpp"

Character::Character() : name("default"), inventory() {
  std::cout << "Character: Default Constructor Called" << std::endl;
}
Character::Character(std::string const& name) : name(name), inventory() {
  std::cout << "Character: Constructor " << name << " Called" << std::endl;
}

Character::~Character() {
  for (int i = 0; i < 4; i++) {
    if (inventory[i]) {
      delete inventory[i];
      inventory[i] = NULL;
    }
  }
  std::cout << "Character: Destructor Called" << std::endl;
}

Character::Character(const Character& character) {
  for (int i = 0; i < 4; i++) {
    delete inventory[i];
    inventory[i] = NULL;
  }
  name = character.getName();
  for (int i = 0; i < 4; i++) {
    if (character.inventory[i]) inventory[i] = character.inventory[i]->clone();
  }
  std::cout << "Character: Copy Called" << std::endl;
}

Character& Character::operator=(Character& character) {
  for (int i = 0; i < 4; i++) {
    delete inventory[i];
    inventory[i] = NULL;
  }
  name = character.getName();
  for (int i = 0; i < 4; i++) {
    if (character.inventory[i]) inventory[i] = character.inventory[i]->clone();
  }
  std::cout << "Character: Operator= Called" << std::endl;
  return (*this);
}

std::string const& Character::getName() const { return (this->name); }

void Character::setName(std::string name) { this->name = name; }

void Character::equip(AMateria* m) {
  if (!m) {
    std::cout << "ERROR: Invalid materia !" << std::endl;
    return;
  }
  for (int i = 0; i < 4; i++) {
    if (inventory[i] == NULL) {
      inventory[i] = m;
      std::cout << "SUCCESS: materia equiped in " << i << " index" << std::endl;
      return;
    }
  }

  std::cout << "ERROR: Inventory Full !" << std::endl;
}

void Character::unequip(int idx) {
  if (inventory[idx] == NULL)
    std::cout << "ERROR: Empty " << idx << " index !" << std::endl;
  else {
    delete inventory[idx];
    inventory[idx] = NULL;
    std::cout << "SUCCESS: Unequiped Complete " << idx << " index !"
              << std::endl;
  }
}

void Character::use(int idx, ICharacter& target) {
  if (inventory[idx])
    inventory[idx]->use(target);
  else
    std::cout << "ERROR: Character Empty Idx" << std::endl;
}