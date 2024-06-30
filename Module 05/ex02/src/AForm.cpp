#include "AForm.hpp"

AForm::AForm (const std::string &name)
	: form_name (name), signed_status (false), grade_required_to_sign (-1),
	  grade_required_to_exec (-1)
{
	std::cout << "Parametrized Form constructor called" << std::endl;
}

AForm::AForm (const AForm &copy)
	: form_name (copy.form_name), signed_status (copy.signed_status),
	  grade_required_to_sign (copy.grade_required_to_sign),
	  grade_required_to_exec (copy.grade_required_to_exec)
{
	std::cout << "Copy Form constructor called" << std::endl;

	*this = copy;
}

AForm::~AForm ()
{
	std::cout << "Default Form destructor called" << std::endl;
}

const std::string &
AForm::get_name ()
{
	return form_name;
}

bool &
AForm::get_signed_status ()
{
	return signed_status;
}

const int &
AForm::get_grade_required_to_sign ()
{
	return grade_required_to_sign;
}

const int &
AForm::get_grade_required_to_exec ()
{
	return grade_required_to_exec;
}

void
AForm::beSigned (Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade () > grade_required_to_sign)
		throw AForm::GradeTooLowException ();

	signed_status = true;
}

const char *
AForm::GradeTooHighException::what () const throw ()
{
	return "Form exception: grade is too high!";
}

const char *
AForm::GradeTooLowException::what () const throw ()
{
	return "Form exception: grade is too low!";
}

AForm &
AForm::operator= (const AForm &copy)
{
	(void)copy;
	return (*this);
}

std::ostream &
operator<< (std::ostream &outstream, AForm &copy)
{
	outstream << "Form " << copy.get_name () << ": Signed status ["
			  << copy.get_signed_status () << "], Grade required to sign ["
			  << copy.get_grade_required_to_sign ()
			  << "], Grade required to exec ["
			  << copy.get_grade_required_to_exec () << "]" << std::endl;

	return outstream;
}
