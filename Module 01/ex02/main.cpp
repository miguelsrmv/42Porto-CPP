#include <iostream>
#include <string>

int
main (void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Memory address of string : " << &string << std::endl;
	std::cout << "Memory address held by string pointer: " << stringPTR
			  << std::endl;
	std::cout << "Memory address held by string reference: " << &stringREF
			  << std::endl;

	std::cout << std::endl;

	std::cout << "Value of string: " << string << std::endl;
	std::cout << "Value pointed to by string pointer: " << *stringPTR
			  << std::endl;
	std::cout << "Value pointed to by string reference: " << stringREF
			  << std::endl;
}
