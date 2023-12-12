#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 private:
  AMateria* inventory[4];

 public:
  MateriaSource();
  ~MateriaSource();
  MateriaSource(const MateriaSource& source);
  MateriaSource& operator=(MateriaSource& source);

  void learnMateria(AMateria* m);
  AMateria* createMateria(std::string const& type);
};

#endif