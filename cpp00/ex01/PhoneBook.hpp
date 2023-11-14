#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

class PhoneBook {
    private:
        int     index;
        int     contactsCount;
        Contact contacts[8];
    public:
        PhoneBook();

        int     getIndex();
        int     getContactCount();
        Contact getContact(int index);
        void    setIndex();
        void    setContactCount();
        void    setContact(Contact contact, int index);
};

void addContact(PhoneBook *phoneBook);
void searchContact(PhoneBook phoneBook);
void printContactList(PhoneBook phoneBook);

#endif