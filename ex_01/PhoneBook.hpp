#pragma once

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <vector> 

class PhoneBook
{
    
public:

    int     iterate;
    int		nb_contact;
    Contact directory[8];
    
    PhoneBook( void );
    ~PhoneBook( void );

};

void    add_contact(PhoneBook &PhoneBook);
void	search_contact(PhoneBook phonebook);
