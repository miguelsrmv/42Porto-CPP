#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void test_form(Bureaucrat& B, AForm& F)
{
	// Prints form to be tested
	std::cout << std::endl << " ** Testing " << F.get_name() << " **" << std::endl ;
	std::cout << F << std::endl;

	// Attempt to sign: grade is too low
	B.signForm(F);
		
	//Increment Grade until one can sign form
	for (int i = B.getGrade(); i >= F.get_grade_required_to_sign(); i--)
		B.incrementGrade();
	B.signForm(F);

	// Attempt to sign: already signed
	B.signForm(F);

	// Attempt to execute: grade is too low
	B.executeForm(F);

	// Increment grade until one can execute form
	for (int i = B.getGrade(); i >= F.get_grade_required_to_exec(); i--)
		B.incrementGrade();
	B.executeForm(F);

	std::cout << std::endl << std::endl ;
}

int main()
{
	// Prints Bureaucrat information
	Bureaucrat B("David", 150);
	std::cout << B << std::endl;

	ShrubberyCreationForm S("Shrubbery_Form");
	test_form(B, S);

	RobotomyRequestForm R("Robotomy_form");
	test_form(B, R);

	PresidentialPardonForm P("Presidential_Form");
	test_form(B, P);
}
