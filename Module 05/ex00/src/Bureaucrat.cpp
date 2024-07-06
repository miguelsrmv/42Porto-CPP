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
	std::cout << "Copy constructor called" << std::endl;
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
	std::cout << "Default destructor called" << std::endl;
}

const char *
Bureaucrat::GradeTooHighException::what () const throw ()
{
	return "Invalid grade: too high!";
}

const char *
Bureaucrat::GradeTooLowException::what () const throw ()
{
	return "Invalid grade: too low!";
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

std::ostream &
operator<< (std::ostream &outstream, Bureaucrat &Bureaucrat)
{
	outstream << Bureaucrat.getName () << ", bureaucrat grade "
			  << Bureaucrat.getGrade () << std::endl;

	return outstream;
}
