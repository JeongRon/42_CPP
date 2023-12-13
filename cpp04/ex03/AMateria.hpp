#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
class ICharacter;

// 추상 클래스
class AMateria {
 protected:
  std::string type;

 public:
  AMateria();
  AMateria(std::string const& type);
  AMateria(const AMateria& materia);
  AMateria& operator=(AMateria& materia);
  virtual ~AMateria();

  std::string const& getType() const;
  virtual void setType(std::string type);

  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);
};

#endif