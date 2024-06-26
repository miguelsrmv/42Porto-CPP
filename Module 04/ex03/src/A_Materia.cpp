#include "A_Materia.hpp"

AMateria::AMateria ()
{
	// std::cout << "AMateria default constructor called" << std::endl ;
}

AMateria::AMateria (std::string const &type) : _materia_type (type)
{
	// std::cout << "AMateria parametrized constructor called" << std::endl ;
}

AMateria::AMateria (const AMateria &copy)
{
	// std::cout << "AMateria copy constructor called" << std::endl ;

	*this = copy;
}

AMateria &
AMateria::operator= (const AMateria &copy)
{
	// std::cout << "AMateria = operator called" << std::endl ;

	if (this != &copy)
		this->_materia_type = copy._materia_type;
	return (*this);
}

AMateria::~AMateria ()
{
	// std::cout << "AMateria destructor called" << std::endl ;
}

std::string const &
AMateria::getType () const
{
	return _materia_type;
}

void
AMateria::use (ICharacter &target)
{
	(void)target;
}
