#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
class ICharacter;

// 추상 클래스
class AMateria {
 protected:
  std::string type;

  AMateria();
  AMateria(std::string const& type);

 public:
  virtual ~AMateria();
  AMateria(const AMateria& materia);
  AMateria& operator=(AMateria& materia);

  std::string const& getType() const;
  virtual void setType(std::string type);

  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);
};

#endif