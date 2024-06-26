#include "A_Animal.hpp"

Animal::Animal () : type ("Animal")
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal (const Animal &copy)
{
	std::cout << "Copy Animal constructor called" << std::endl;

	*this = copy;
}

Animal &
Animal::operator= (const Animal &copy)
{
	std::cout << "Animal = operator called" << std::endl;

	if (this != &copy)
		{
			this->type = copy.type;
		}
	return (*this);
}

Animal::~Animal ()
{
	std::cout << "Default Animal destructor called" << std::endl;
}

void
Animal::makeSound () const
{
	std::cout << this->type << " made a sound!" << std::endl;
}

std::string
Animal::getType () const
{
	return type;
}
