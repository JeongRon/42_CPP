#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 public:
  ScavTrap();
  ScavTrap(std::string name);
  ~ScavTrap();
  ScavTrap(ScavTrap& scavTrap);
  ScavTrap& operator=(const ScavTrap& scavTrap);

  void attack(std::string const& target);
  void guardGate(void);
};

#endif