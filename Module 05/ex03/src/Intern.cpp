#include "Intern.hpp"

Intern::Intern () {}

Intern::Intern (const Intern &copy) { (void)copy; }

const Intern &
Intern::operator= (const Intern &copy)
{
	(void)copy;
	return *this;
}

Intern::~Intern () {}

AForm *
Intern::makeForm (const std::string &form_name,
				  const std::string &form_target) const
{
	// Get form index_number for function pointer list
	int form_name_index = 0;
	const std::string form_name_list[3]
		= { "presidential pardon", "robotomy request", "shrubbery creation" };
	while (form_name_index < 3 && form_name_list[form_name_index] != form_name)
		form_name_index++;

	// Exits if form_name was not found
	if (form_name_index == 3)
		{
			std::cout << "Invalid form (" << form_name << ")!" << std::endl;
			return NULL;
		}

	// Create array of function pointers
	AForm *(Intern::*creation_list[3]) (const std::string &target) const
		= { &Intern::createPresidentialPardornForm,
			&Intern::createRobotomyRequestForm,
			&Intern::createShrubberyCreationForm };

	// Prints message
	std::cout << "Intern creates " << form_name << std::endl;

	// Executes function pointer, returning pointer to new function
	return (this->*creation_list[form_name_index]) (form_target);
}

AForm *
Intern::createPresidentialPardornForm (const std::string &target) const
{
	return new PresidentialPardonForm (target);
}

AForm *
Intern::createRobotomyRequestForm (const std::string &target) const
{
	return new RobotomyRequestForm (target);
}

AForm *
Intern::createShrubberyCreationForm (const std::string &target) const
{
	return new ShrubberyCreationForm (target);
}
