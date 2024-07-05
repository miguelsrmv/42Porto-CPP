#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void test_form(Bureaucrat& B, AForm& F)
{
	std::cout << " ** Testing " << F.get_name() << " **" << std::endl ;

	// Attempt to sign: grade is too low
	B.signForm(F);
		
	//Increment Grade
	for (int i = B.getGrade(); i >= F.get_grade_required_to_sign(); i--)
		B.incrementGrade();

	// Sign Form
	B.signForm(F);

	// Attempt to sign: already signed
	B.signForm(F);

	// Attempt to execute: grade is too low
	B.executeForm(F);

	// Increment grade
	for (int i = B.getGrade(); i >= F.get_grade_required_to_exec(); i--)
		B.incrementGrade();

	// Execute Form
	B.executeForm(F);

	std::cout << std::endl << std::endl ;
}

int main()
{
	Bureaucrat B("David", 150);
	std::cout << B << std::endl;

	ShrubberyCreationForm S("Shrubbery_Form");
	std::cout << S << std::endl;

	test_form(B, S);

	RobotomyRequestForm R("Robotomy_form");
	std::cout << R << std::endl;
	
	test_form(B, R);

	PresidentialPardonForm P("Presidential_Form");
	std::cout << P << std::endl;

	test_form(B, P);
}
