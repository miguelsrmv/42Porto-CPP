#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat (std::string name, int grade) : name (name)
{
	std::cout << "Parametrized Bureaucrat constructor called" << std::endl;

	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException ();
	else if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException ();

	this->grade = grade;
}

Bureaucrat::Bureaucrat (const Bureaucrat &copy)
	: name (copy.name), grade (copy.grade)
{
	std::cout << "Copy Bureaucrat constructor called" << std::endl;
}

Bureaucrat &
Bureaucrat::operator= (const Bureaucrat &copy)
{
	if (this != &copy)
		{
			this->grade = copy.grade;
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
	return (name);
}

int
Bureaucrat::getGrade ()
{
	return grade;
}

void
Bureaucrat::incrementGrade ()
{
	if (grade == MAX_GRADE)
		throw Bureaucrat::GradeTooHighException ();
	grade--;
}

void
Bureaucrat::decrementGrade ()
{
	if (grade == MIN_GRADE)
		throw Bureaucrat::GradeTooLowException ();
	grade++;
}

void
Bureaucrat::signForm (AForm &form)
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
