#include "Dog.hpp"

Dog::Dog ()
{
	std::cout << "Default Dog constructor called" << std::endl;

	type = "Dog";
}

Dog::Dog (const Dog &copy) : Animal (copy)
{
	std::cout << "Copy Dog constructor called" << std::endl;

	*this = copy;
}

Dog &
Dog::operator= (const Dog &copy)
{
	std::cout << "Dog = operator called" << std::endl;

	if (this != &copy)
		{
			this->type = copy.type;
		}
	return (*this);
}

Dog::~Dog () { std::cout << "Default Dog destructor called" << std::endl; }

void
Dog::makeSound () const
{
	std::cout << this->type << " barked!" << std::endl;
}
