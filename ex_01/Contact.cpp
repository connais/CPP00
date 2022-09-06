#include "PhoneBook.hpp"


Contact::Contact( void )
{
    this->infos = 0;
    return ;
}

Contact::~Contact( void )
{
    return ;
}

void	print_each_info(std::string given)
{
	std::string::iterator it;
	int i = 0;
	int	lenght = 10 - given.length();

//	std::cout << "lenght : " << lenght << std::endl;
	if (lenght > 0)
	{
		while(lenght > 0)
		{
			std::cout << " ";
			lenght--; 
		}
	}
	for( it = given.begin(); (it != given.end() && i < 10); ++it)
	{
		std::cout << *it;
		i++;
	}
	if (given.length() > 10)
		std::cout <<".";
	std::cout << "|";
}
void	print_good(std::string info)
{
	std::string::iterator it;
	int i = 0;
	
	for( it = info.begin(); it != info.end(); ++it)
	{
		std::cout << *it;
		i++;
	}
	std::cout << std::endl;
}
void	print_full_contact(Contact contact)
{
	std::cout << "first name : "; 
	print_good(contact.first_name);
	std::cout << "last name : ";
	print_good(contact.last_name);
	std::cout << "nickname : "; 
	print_good(contact.nickname);
	std::cout << "phone number : "; 
	print_good(contact.phone_number);
	std::cout << "dark secret : "; 
	print_good(contact.darkest_secret);
}
void	choose_one(PhoneBook phonebook)
{
	std::string index;
    int inputAsInt;

	std::cout << "enter the index of the contact to display" << std::endl;
	std::getline(std::cin, index);
	while(std::cin.fail() || index == "" || std::cin.eof() || index.size() > 1  || index.find_first_not_of("01234567") != std::string::npos)
	{
		std::cout << "Bad input" << std::endl;
		std::getline(std::cin, index);
	}
	inputAsInt = atoi(index.c_str());
//	std::cout << "input : " << inputAsInt << std::endl;
	if (inputAsInt < phonebook.nb_contact)
		print_full_contact(phonebook.directory[inputAsInt]);
	else
		choose_one(phonebook);
}

void	print_column(Contact contact)
{
	std::cout << contact.infos << "|";
	print_each_info(contact.first_name);
	print_each_info(contact.last_name);
	print_each_info(contact.nickname);

}

void	print_all_contacts(PhoneBook PhoneBook)
{
	int	i;

	i = -1;
	while (++i < PhoneBook.nb_contact)
	{
		print_column(PhoneBook.directory[i]);
		std::cout << std::endl;
	}
}

void	search_contact(PhoneBook phonebook)
{
	print_all_contacts(phonebook);
	choose_one(phonebook);
}