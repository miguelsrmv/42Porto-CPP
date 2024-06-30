#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat (std::string name, int grade) : name (name)
{
	std::cout << "Parametrized constructor called" << std::endl;

	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException ();
	else if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException ();

	this->grade = grade;
}

Bureaucrat::Bureaucrat (const Bureaucrat &copy) : Bureaucrat(copy.name, copy.grade)
{
	std::cout << "Copy constructor called" << std::endl;

	*this = copy;
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
	std::cout << "Default destructor called" << std::endl;
}

std::string
Bureaucrat::GradeTooHighException::too_high_message () const
{
	std::string message = "Invalid grade: too high!";

	return message;
}

std::string
Bureaucrat::GradeTooLowException::too_low_message () const
{
	std::string message = "Invalid grade: too low!";

	return message;
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

std::ostream &
operator<< (std::ostream &outstream, Bureaucrat &Bureaucrat)
{
	outstream << Bureaucrat.getName () << ", bureaucrat grade "
			  << Bureaucrat.getGrade () << std::endl;

	return outstream;
}
