#include "Cure.hpp"

Cure::Cure () : AMateria ("cure")
{
	// std::cout << "Cure parametrized constructor called" << std::endl ;
}

Cure::Cure (const Cure &copy) : AMateria ("cure")
{
	// std::cout << "Cure copy constructor called" << std::endl ;

	*this = copy;
}

Cure &
Cure::operator= (const Cure &copy)
{
	// std::cout << "Cure = operator called" << std::endl ;

	if (this != &copy)
		this->_materia_type = copy._materia_type;
	return (*this);
}

Cure::~Cure ()
{
	// std::cout << "Cure destructor called" << std::endl ;
}

void
Cure::use (ICharacter &target)
{
	std::cout << "* heals " << target.getName () << "'s wounds *" << std::endl;
}

Cure *
Cure::clone () const
{
	return (new Cure (*this));
}
