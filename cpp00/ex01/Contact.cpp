#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string *contactInfo) {
  this->firstName = contactInfo[0];
  this->lastName = contactInfo[1];
  this->nickName = contactInfo[2];
  this->phoneNumber = contactInfo[3];
  this->darkestSecret = contactInfo[4];
}

// index, first name, last name, nickname
void Contact::printContact(int index) {
  std::string tmp;

  std::cout << std::setw(10);
  std::cout << index;
  std::cout << "|";
  if (this->firstName.length() > 10) {
    tmp = this->firstName.substr(0, 9);
    std::cout << tmp << ".";
  } else {
    std::cout << std::setw(10);
    std::cout << this->firstName;
  }
  std::cout << "|";
  if (this->lastName.length() > 10) {
    tmp = this->lastName.substr(0, 9);
    std::cout << tmp << ".";
  } else {
    std::cout << std::setw(10);
    std::cout << this->lastName;
  }
  std::cout << "|";
  if (this->nickName.length() > 10) {
    tmp = this->nickName.substr(0, 9);
    std::cout << tmp << ".";
  } else {
    std::cout << std::setw(10);
    std::cout << this->nickName;
  }
  std::cout << "|" << std::endl;
}

// first name, last name, nickname, phone number, darkest secret
void Contact::printContactDetail() {
  std::cout << "first name : " << this->firstName << std::endl;
  std::cout << "last name : " << this->lastName << std::endl;
  std::cout << "nick name : " << this->nickName << std::endl;
  std::cout << "phone number : " << this->phoneNumber << std::endl;
  std::cout << "darkest secret : " << this->darkestSecret << std::endl;
}