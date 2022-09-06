#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void )
{
    this->iterate = 0;
	this->nb_contact = 0;
    return ;
}
PhoneBook::~PhoneBook( void )
{
    return ;
}

std::string	update(std::string info)
{
	std::string param = "";

	std::cout << info;
	while (std::getline(std::cin, param) && param == "")
	{
		if (param == "")
			std::cout << "incorrect information, please try again" << std::endl;
		std::cout << info;
	}
	return (param);
}

void	new_contact(Contact &contact)
{
	std::cout << "Enter your personal information" << std::endl;
	contact.first_name = update("first name : ");
	contact.last_name = update("last name : ");
	contact.nickname = update("nickname : ");
    contact.phone_number = update("phone_number : ");
    contact.darkest_secret = update("dark secret : ");
//	std::cout << contact.first_name << std::endl;
//	std::cout << contact.last_name << std::endl;

}
void    add_contact(PhoneBook &PhoneBook)
{
	std::cout << "start " << PhoneBook.iterate << std::endl;
	new_contact(PhoneBook.directory[PhoneBook.iterate]);
	PhoneBook.iterate = (PhoneBook.iterate + 1 == 8) ? 0 : ++PhoneBook.iterate;
	if (PhoneBook.nb_contact < 8)
		PhoneBook.nb_contact++;
	PhoneBook.directory[PhoneBook.iterate].infos = PhoneBook.iterate;
}