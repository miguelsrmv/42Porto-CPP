#include "Cat.hpp"

Cat::Cat ()
{
	std::cout << "Default Cat constructor called" << std::endl;

	animal_brain = new Brain;

    type = "Cat";
}

Cat::Cat (const Cat &copy) : Animal (copy)
{
	std::cout << "Copy Cat constructor called" << std::endl;

	animal_brain = NULL;
	*this = copy;;
}

Cat &
Cat::operator= (const Cat &copy)
{
	std::cout << "Cat = operator called" << std::endl;

	if (this != &copy)
		{
			delete this->animal_brain;
			this->animal_brain = new Brain (*copy.animal_brain);
		}
	return (*this);
}

Cat::~Cat ()
{
	std::cout << "Default Cat destructor called" << std::endl;

	delete animal_brain;
}

void
Cat::makeSound() const
{
    std::cout << this->type << " mewoed!" << std::endl ;
}
