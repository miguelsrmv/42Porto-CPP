#include "Ice_Materia.hpp"

Ice_Materia::Ice_Materia() : AMateria("ice")
{
    //std::cout << "Ice_Materia parametrized constructor called" << std::endl ;
}

Ice_Materia::Ice_Materia(const Ice_Materia& copy) : AMateria("ice")
{
    //std::cout << "Ice_Materia copy constructor called" << std::endl ;

    *this = copy;
}

Ice_Materia&
Ice_Materia::operator=(const Ice_Materia& copy)
{
    //std::cout << "Ice_Materia = operator called" << std::endl ;

    if (this != &copy)
        this->materia_type = copy.materia_type;
    return (*this);
}

Ice_Materia::~Ice_Materia()
{
    //std::cout << "Ice_Materia destructor called" << std::endl ;
}

void
Ice_Materia::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl ;
}

Ice_Materia *
Ice_Materia::clone() const
{
    return (new Ice_Materia(*this));
}
