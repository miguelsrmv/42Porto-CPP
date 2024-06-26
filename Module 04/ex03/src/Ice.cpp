#include "Ice.hpp"

Ice::Ice () : AMateria ("ice")
{
	// std::cout << "Ice parametrized constructor called" << std::endl ;
}

Ice::Ice (const Ice &copy) : AMateria ("ice")
{
	// std::cout << "Ice copy constructor called" << std::endl ;

	*this = copy;
}

Ice &
Ice::operator= (const Ice &copy)
{
	// std::cout << "Ice = operator called" << std::endl ;

	if (this != &copy)
		this->_materia_type = copy._materia_type;
	return (*this);
}

Ice::~Ice ()
{
	// std::cout << "Ice destructor called" << std::endl ;
}

void
Ice::use (ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName () << " *"
			  << std::endl;
}

Ice *
Ice::clone () const
{
	return (new Ice (*this));
}
