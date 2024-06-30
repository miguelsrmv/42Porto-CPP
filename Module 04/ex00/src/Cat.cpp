#include "Cat.hpp"

Cat::Cat ()
{
	std::cout << "Default Cat constructor called" << std::endl;

	type = "Cat";
}

Cat::Cat (const Cat &copy) : Animal (copy)
{
	std::cout << "Copy Cat constructor called" << std::endl;

	*this = copy;
}

Cat &
Cat::operator= (const Cat &copy)
{
	std::cout << "Cat = operator called" << std::endl;

	if (this != &copy)
		{
			this->type = copy.type;
		}
	return (*this);
}

Cat::~Cat () { std::cout << "Default Cat destructor called" << std::endl; }

void
Cat::makeSound () const
{
	std::cout << this->type << " mewoed!" << std::endl;
}
