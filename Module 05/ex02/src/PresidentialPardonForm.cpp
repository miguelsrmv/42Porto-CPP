#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 72, 45), _target(target)
{
	std::cout << "Parametrized PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy), _target(copy._target)
{
	std::cout << "Copy PresidentialPardonForm constructor called" << std::endl ;

	*this = copy;
}

PresidentialPardonForm&
PresidentialPardonForm::operator =(const PresidentialPardonForm& copy)
{
	(void)copy;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Default PresidentialPardonForm destructor called" << std::endl;
}

void
PresidentialPardonForm::execute(void) const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox!" << std::endl ;
}
