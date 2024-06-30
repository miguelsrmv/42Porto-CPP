#include "WrongDog.hpp"

WrongDog::WrongDog ()
{
	std::cout << "Default WrongDog constructor called" << std::endl;

	type = "WrongDog";
}

WrongDog::WrongDog (const WrongDog &copy) : WrongAnimal (copy)
{
	std::cout << "Copy WrongDog constructor called" << std::endl;

	*this = copy;
}

WrongDog &
WrongDog::operator= (const WrongDog &copy)
{
	std::cout << "WrongDog = operator called" << std::endl;

	if (this != &copy)
		{
			this->type = copy.type;
		}
	return (*this);
}

WrongDog::~WrongDog ()
{
	std::cout << "Default WrongDog destructor called" << std::endl;
}

void
WrongDog::makeSound () const
{
	std::cout << this->type << " mewoed!" << std::endl;
}
