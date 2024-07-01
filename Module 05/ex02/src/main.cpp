#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat B("David", 150);
	std::cout << B << std::endl;

	ShrubberyCreationForm S("Form_1");
	std::cout << S << std::endl;

	RobotomyRequestForm R("Form_2");
	std::cout << R << std::endl;

	PresidentialPardonForm P("Form_3");
	std::cout << P << std::endl;

/* // Grade is too low
	B.signForm(S);
	std::cout << std::endl;

//Increment Grade
	B.incrementGrade();
	B.signForm(S);
	std::cout << std::endl;
	B.executeForm(S);
	std::cout << std::endl;

	B.executeForm(R);
	std::cout << std::endl;
	B.signForm(R);
	std::cout << std::endl;

	B.executeForm(R);
	std::cout << std::endl;
	B.signForm(P);
	std::cout << std::endl;
	B.executeForm(P);
	return 0; */
}
