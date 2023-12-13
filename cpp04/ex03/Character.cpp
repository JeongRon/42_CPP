#include "Character.hpp"

#include "AMateria.hpp"

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
    std::cout << "Character equip ERROR: Invalid materia !" << std::endl;
    return;
  }
  for (int i = 0; i < 4; i++) {
    if (inventory[i] == NULL) {
      inventory[i] = m;
      std::cout << "Character equip SUCCESS: materia equiped in " << i
                << " index" << std::endl;
      return;
    }
  }

  std::cout << "Character equip ERROR: Inventory Full !" << std::endl;
}

void Character::unequip(int idx) {
  if (idx < 0 || 3 < idx)
    std::cout << "Character unequip ERROR: index range !" << std::endl;
  else if (inventory[idx] == NULL)
    std::cout << "Character unequip ERROR: Empty " << idx << " index !"
              << std::endl;
  else {
    inventory[idx] = NULL;
    std::cout << "Character unequip SUCCESS: Unequiped Complete " << idx
              << " index !" << std::endl;
  }
}

void Character::use(int idx, ICharacter& target) {
  if (idx < 0 || 3 < idx)
    std::cout << "Character use ERROR: index range !" << std::endl;
  else if (inventory[idx])
    inventory[idx]->use(target);
  else
    std::cout << "Character use ERROR: Character Empty Idx" << std::endl;
}