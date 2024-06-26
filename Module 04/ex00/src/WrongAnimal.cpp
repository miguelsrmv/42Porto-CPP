#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal () : type ("WrongAnimal")
{
	std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal (const WrongAnimal &copy)
{
	std::cout << "Copy WrongAnimal constructor called" << std::endl;

	*this = copy;
}

WrongAnimal &
WrongAnimal::operator= (const WrongAnimal &copy)
{
	std::cout << "WrongAnimal = operator called" << std::endl;

	if (this != &copy)
		{
			this->type = copy.type;
		}
	return (*this);
}

WrongAnimal::~WrongAnimal ()
{
	std::cout << "Default WrongAnimal destructor called" << std::endl;
}

void
WrongAnimal::makeSound () const
{
	std::cout << this->type << " made a sound!" << std::endl;
}

std::string
WrongAnimal::getType () const
{
	return type;
}
