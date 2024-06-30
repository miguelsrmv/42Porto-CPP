#include "Dog.hpp"

Dog::Dog ()
{
	std::cout << "Default Dog constructor called" << std::endl;

	animal_brain = new Brain;

    type = "Dog";
}

Dog::Dog (const Dog &copy) : Animal (copy)
{
	std::cout << "Copy Dog constructor called" << std::endl;

	animal_brain = new Brain (*copy.animal_brain);
}

Dog &
Dog::operator= (const Dog &copy)
{
	std::cout << "Dog = operator called" << std::endl;

	if (this != &copy)
		{
			Animal::operator= (copy);
			delete this->animal_brain;
			this->animal_brain = new Brain (*copy.animal_brain);
		}
	return (*this);
}

Dog::~Dog ()
{
	std::cout << "Default Dog destructor called" << std::endl;

	delete animal_brain;
}

void
Dog::makeSound() const
{
    std::cout << this->type << " barked!" << std::endl ;
}
