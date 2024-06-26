#include "Cure_Materia.hpp"

Cure_Materia::Cure_Materia() : AMateria ("cure")
{
    //std::cout << "Cure_Materia parametrized constructor called" << std::endl ;
}

Cure_Materia::Cure_Materia(const Cure_Materia& copy) : AMateria("cure")
{
    //std::cout << "Cure_Materia copy constructor called" << std::endl ;

    *this = copy;
}

Cure_Materia&
Cure_Materia::operator=(const Cure_Materia& copy)
{
    //std::cout << "Cure_Materia = operator called" << std::endl ;

    if (this != &copy)
        this->materia_type = copy.materia_type;
    return (*this);
}

Cure_Materia::~Cure_Materia()
{
    //std::cout << "Cure_Materia destructor called" << std::endl ;
}

void
Cure_Materia::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl ;
}

Cure_Materia *
Cure_Materia::clone() const
{
    return (new Cure_Materia(*this));
}
