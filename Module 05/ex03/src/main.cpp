#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void
test_form_creation (const std::string &form_name,
					const std::string &target_name)
{
	std::cout << std::endl;

	Intern someRandomIntern;
	AForm *form;

	form = someRandomIntern.makeForm (form_name, target_name);

	delete form;
}

int
main ()
{
	test_form_creation ("robotomy request", "Bender");
	test_form_creation ("presidential pardon", "Charlie");
	test_form_creation ("shrubbery creation", "Dennis");
	test_form_creation ("non-existant", "Eagle");
}
