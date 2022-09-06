#include "Contact.hpp"
#include "PhoneBook.hpp"


int main()
{
   std::string command;
   PhoneBook phonebook;
   
   std::cout << "choose your command : ADD | SEARCH | EXIT" << std::endl;
   while (std::getline(std::cin, command))
   {
      if (command == "ADD")
         add_contact(phonebook);
      else if (command == "SEARCH")
         search_contact(phonebook);
      else if (command == "EXIT")
         return (0);
      std::cout << "choose your command : ADD | SEARCH | EXIT" << std::endl;
      //std::cout << "hello " << phonebook.directory[0].first_name << " " << phonebook.directory[0].last_name << std::endl;
   }
}