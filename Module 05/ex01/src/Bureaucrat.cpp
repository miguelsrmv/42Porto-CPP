#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat (std::string name, int grade) : _name (name)
{
	std::cout << "Parametrized constructor called" << std::endl;

	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException ();
	else if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException ();

	this->_grade = grade;
}
Bureaucrat::Bureaucrat (const Bureaucrat &copy)
	: _name (copy._name), _grade (copy._grade)
{
	std::cout << "Copy Bureaucrat constructor called" << std::endl;
}

Bureaucrat &
Bureaucrat::operator= (const Bureaucrat &copy)
{
	if (this != &copy)
		{
			this->_grade = copy._grade;
			// this->name = copy.name;   // Not possible because name is const
		}
	return (*this);
}

Bureaucrat::~Bureaucrat ()
{
	std::cout << "Default Bureaucrat destructor called" << std::endl;
}

const char *
Bureaucrat::GradeTooHighException::what () const throw ()
{
	return "Invalid bureaucrat grade: too high!";
}

const char *
Bureaucrat::GradeTooLowException::what () const throw ()
{
	return "Invalid bureaucrat grade: too low!";
}

std::string
Bureaucrat::getName ()
{
	return _name;
}

int
Bureaucrat::getGrade ()
{
	return _grade;
}

void
Bureaucrat::incrementGrade ()
{
	if (_grade == MAX_GRADE)
		throw Bureaucrat::GradeTooHighException ();
	_grade--;
}

void
Bureaucrat::decrementGrade ()
{
	if (_grade == MIN_GRADE)
		throw Bureaucrat::GradeTooLowException ();
	_grade++;
}

void
Bureaucrat::signForm (Form &form)
{
	if (form.get_signed_status ())
		{
			std::cout << this->getName () << " couldn't sign "
					  << form.get_name () << " because it was already signed! "
					  << std::endl;
		}
	else if (this->getGrade () > form.get_grade_required_to_sign ())
		{
			std::cout << this->getName () << " couldn't sign form "
					  << form.get_name () << " because his level was too low ("
					  << this->getGrade () << ", required "
					  << form.get_grade_required_to_sign () << ")."
					  << std::endl;
		}
	else
		{
			std::cout << this->getName () << " signed " << form.get_name ()
					  << std::endl;
		}
	form.beSigned (*this);
}

std::ostream &
operator<< (std::ostream &outstream, Bureaucrat &Bureaucrat)
{
	outstream << Bureaucrat.getName () << ", bureaucrat grade "
			  << Bureaucrat.getGrade () << std::endl;

	return outstream;
}
