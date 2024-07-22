#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm (const std::string &target)
	: AForm ("RobotomyRequestForm", 72, 45), _target (target)
{
	std::cout << "Parametrized RobotomyRequestForm constructor called"
			  << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm (const RobotomyRequestForm &copy)
	: AForm (copy), _target (copy._target)
{
	std::cout << "Copy RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm &
RobotomyRequestForm::operator= (const RobotomyRequestForm &copy)
{
	// Unable to change parameters because they are private and there are no
	// setters
	(void)copy;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm ()
{
	std::cout << "Default RobotomyRequestForm destructor called" << std::endl;
}

void
RobotomyRequestForm::execute (void) const
{
	std::srand (std::time (NULL));

	std::cout
		<< "* Drilling noises * WHIIRLLL... WHIRLLL... * Drilling noises *"
		<< std::endl;
	if (std::rand () % 2)
		std::cout << _target << " has been successfully robotomized!"
				  << std::endl;
	else
		std::cout << "Robotomy status: Oops..." << std::endl;
}
