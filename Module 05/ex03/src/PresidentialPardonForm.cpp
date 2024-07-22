#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm (const std::string &target)
	: AForm ("PresidentialPardonForm", 25, 5), _target (target)
{
	std::cout << "Parametrized PresidentialPardonForm constructor called"
			  << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm (
	const PresidentialPardonForm &copy)
	: AForm (copy), _target (copy._target)
{
	std::cout << "Copy PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm &
PresidentialPardonForm::operator= (const PresidentialPardonForm &copy)
{
	// Unable to change parameters because they are private and there are no setters
	(void)copy;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm ()
{
	std::cout << "Default PresidentialPardonForm destructor called"
			  << std::endl;
}

void
PresidentialPardonForm::execute (void) const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox!"
			  << std::endl;
}
