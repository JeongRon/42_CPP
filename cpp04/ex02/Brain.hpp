#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
 private:
  std::string ideas[100];

 public:
  Brain();
  ~Brain();
  Brain(const Brain& brain);
  Brain& operator=(Brain& brain);

  std::string getIdeas(int index) const;
  void setIdeas(int index, std::string value);
};

#endif