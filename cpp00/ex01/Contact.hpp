#ifndef CONTACT_H
#define CONTACT_H

#include <iomanip>
#include <iostream>

class Contact {
 private:
  std::string firstName;
  std::string lastName;
  std::string nickName;
  std::string phoneNumber;
  std::string darkestSecret;

 public:
  Contact();
  Contact(std::string *contactInfo);

  void printContact(int index);
  void printContactDetail();
};

#endif