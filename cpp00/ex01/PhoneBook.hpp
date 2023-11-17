#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>

#include "Contact.hpp"

class PhoneBook {
 private:
  int index;
  int contactsCount;
  Contact contacts[8];

 public:
  PhoneBook();

  int getIndex();
  int getContactCount();
  Contact getContact(int index);
  void plusIndex();
  void plusContactCount();
  void setContact(Contact contact, int index);

  void addContact();
  void searchContact();
  void printContactList();
};

#endif