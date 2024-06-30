#include "WrongCat.hpp"

WrongCat::WrongCat ()
{
	std::cout << "Default WrongCat constructor called" << std::endl;

	type = "WrongCat";
}

WrongCat::WrongCat (const WrongCat &copy) : WrongAnimal (copy)
{
	std::cout << "Copy WrongCat constructor called" << std::endl;

	*this = copy;
}

WrongCat &
WrongCat::operator= (const WrongCat &copy)
{
	std::cout << "WrongCat = operator called" << std::endl;

	if (this != &copy)
		{
			this->type = copy.type;
		}
	return (*this);
}

WrongCat::~WrongCat ()
{
	std::cout << "Default WrongCat destructor called" << std::endl;
}

void
WrongCat::makeSound () const
{
	std::cout << this->type << " mewoed!" << std::endl;
}
