#include "AForm.hpp"

AForm::AForm (const std::string &name, int sign_grade, int exec_grade)
	: _form_name (name), _signed_status (false),
	  _grade_required_to_sign (sign_grade),
	  _grade_required_to_exec (exec_grade)
{
	std::cout << "Parametrized AForm constructor called" << std::endl;
}

AForm::AForm (const AForm &copy)
	: _form_name (copy._form_name), _signed_status (copy._signed_status),
	  _grade_required_to_sign (copy._grade_required_to_sign),
	  _grade_required_to_exec (copy._grade_required_to_exec)
{
	std::cout << "Copy AForm constructor called" << std::endl;
}

AForm &
AForm::operator= (const AForm &copy)
{
	if (this != &copy)
		{
			this->_signed_status = copy._signed_status;
		}
	return (*this);
}

AForm::~AForm ()
{
	std::cout << "Default AForm destructor called" << std::endl;
}

const std::string &
AForm::get_name () const
{
	return _form_name;
}

bool
AForm::get_signed_status () const
{
	return _signed_status;
}

int
AForm::get_grade_required_to_sign () const
{
	return _grade_required_to_sign;
}

int
AForm::get_grade_required_to_exec () const
{
	return _grade_required_to_exec;
}

void
AForm::beSigned (Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade () > _grade_required_to_sign)
		{
			throw AForm::GradeTooLowException ();
			return;
		}

	_signed_status = true;
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

const char *
AForm::FormNotSignedException::what () const throw ()
{
	return "Form exception: form is not signed!";
}

void
AForm::execute (Bureaucrat const &executor) const
{
	if (((Bureaucrat &)executor).getGrade ()
		> this->get_grade_required_to_exec ())
		{
			throw AForm::GradeTooLowException ();
		}
	else if (!this->get_signed_status ())
		{
			throw AForm::FormNotSignedException ();
		}
	else
		this->execute ();
}

std::ostream &
operator<< (std::ostream &outstream, const AForm &copy)
{
	outstream << "Form " << copy.get_name () << ": Signed status ["
			  << copy.get_signed_status () << "], Grade required to sign ["
			  << copy.get_grade_required_to_sign ()
			  << "], Grade required to exec ["
			  << copy.get_grade_required_to_exec () << "]" << std::endl;

	return outstream;
}
