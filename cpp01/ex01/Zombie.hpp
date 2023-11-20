#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
 private:
  std::string name;

 public:
  Zombie();                  // constructor
  Zombie(std::string name);  // constructor
  ~Zombie();                 // destructor

  void announce(void);
  void setZombieName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif