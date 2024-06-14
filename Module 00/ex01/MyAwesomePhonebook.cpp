#include "PhoneBook.hpp"
#include <cstring>
#include <iostream>
#include <string>

int main(void)
{
	std::string input;
	PhoneBook phonebook;

	std::cout << "Welcome to MyAwesomePhonebook!" << std::endl;
	std::cout << "Let's create your very own phonebook!" << std::endl
			  << std::endl;

	while (true)
	{
		std::cout << "Enter a command (SEARCH, ADD or EXIT): ";
		if (!std::getline(std::cin, input))
			break;
		if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
		else if (input == "EXIT")
		{
			std::cout << "Exiting!" << std::endl;
			break;
		}
		else
			std::cout << "Error: Invalid input" << std::endl;
		if (std::cin.eof())
			break ;
	}
}
