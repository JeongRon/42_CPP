#include "Brain.hpp"

Brain::Brain() {
  for (int i = 0; i < 100; i++) {
    ideas[i] = "Default";
  }
  std::cout << "Brain: Default Constructor Called" << std::endl;
}

Brain::~Brain() { std::cout << "Brain: Destructor Called" << std::endl; }

Brain::Brain(const Brain& brain) {
  for (int i = 0; i < 100; i++) {
    this->setIdeas(i, brain.getIdeas(i));
  }
  std::cout << "Brain: Copy Constructor Called" << std::endl;
}

Brain& Brain::operator=(Brain& brain) {
  for (int i = 0; i < 100; i++) {
    this->setIdeas(i, brain.getIdeas(i));
  }
  std::cout << "Brain: Operator= Called" << std::endl;
  return (*this);
}

std::string Brain::getIdeas(int index) const { return ideas[index]; }

void Brain::setIdeas(int index, std::string value) { ideas[index] = value; }
