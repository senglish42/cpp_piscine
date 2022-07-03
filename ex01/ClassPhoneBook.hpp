#ifndef CLASS_PHONEBOOK_HPP
#define CLASS_PHONEBOOK_HPP

#include "ClassContact.hpp"

class PhoneBook {
    public:
        PhoneBook( void );
        ~PhoneBook( void );
        void to_send(Contact contact, int num);
        void to_search(int num);
    private:
        Contact contact_[8];
};

#endif