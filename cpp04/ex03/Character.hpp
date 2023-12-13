#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
 private:
  std::string name;
  AMateria* inventory[4];

 public:
  Character();
  Character(std::string const& name);
  ~Character();
  Character(const Character& character);
  Character& operator=(Character& character);

  std::string const& getName() const;
  void setName(std::string name);

  void equip(AMateria* m);
  void unequip(int idx);
  void use(int idx, ICharacter& target);
};

#endif