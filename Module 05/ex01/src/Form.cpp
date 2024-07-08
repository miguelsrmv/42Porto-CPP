#include "Form.hpp"

Form::Form (const std::string &name, const int grade_to_sign,
			const int grade_to_exec)
	: _form_name (name), _signed_status (false),
	  _grade_required_to_sign (grade_to_sign),
	  _grade_required_to_exec (grade_to_exec)
{
	std::cout << "Parametrized Form constructor called" << std::endl;

	if (grade_to_exec < MAX_GRADE || grade_to_sign < MAX_GRADE)
		throw Form::GradeTooHighException ();
	else if (grade_to_exec > MIN_GRADE || grade_to_sign > MIN_GRADE)
		throw Form::GradeTooLowException ();
}

Form::Form (const Form &copy)
	: _form_name (copy._form_name), _signed_status (copy._signed_status),
	  _grade_required_to_sign (copy._grade_required_to_sign),
	  _grade_required_to_exec (copy._grade_required_to_exec)
{
	std::cout << "Copy Form constructor called" << std::endl;

	*this = copy;
}

Form &
Form::operator= (const Form &copy)
{
	if (this != &copy)
	{
		this->_signed_status = copy._signed_status;
	}
	return (*this);
}

Form::~Form () { std::cout << "Default Form destructor called" << std::endl; }

const std::string &
Form::get_name ()
{
	return _form_name;
}

bool &
Form::get_signed_status ()
{
	return _signed_status;
}

const int &
Form::get_grade_required_to_sign ()
{
	return _grade_required_to_sign;
}

const int &
Form::get_grade_required_to_exec ()
{
	return _grade_required_to_exec;
}

void
Form::beSigned (Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade () > _grade_required_to_sign)
	{
		throw Form::GradeTooLowException ();
		return ;
	}

	_signed_status = true;
}

const char *
Form::GradeTooHighException::what () const throw ()
{
	return "Form exception: grade is too high!";
}

const char *
Form::GradeTooLowException::what () const throw ()
{
	return "Form exception: grade is too low!";
}

std::ostream &
operator<< (std::ostream &outstream, Form &copy)
{
	outstream << "Form " << copy.get_name () << ": Signed status ["
			  << copy.get_signed_status () << "], Grade required to sign ["
			  << copy.get_grade_required_to_sign ()
			  << "], Grade required to exec ["
			  << copy.get_grade_required_to_exec () << "]" << std::endl;

	return outstream;
}
