#ifndef BREAUCRAT_HPP
#define BREAUCRAT_HPP

#include "Form.hpp"
#include <exception>
#include <iostream>
#include <string>

#define MIN_GRADE 150
#define MAX_GRADE 1

class Form;

class Bureaucrat
{
  public:
	// Exceptions
	class GradeTooHighException : public std::exception
	{
	  public:
		const char *what () const throw ();
	};
	class GradeTooLowException : public std::exception
	{
	  public:
		const char *what () const throw ();
	};

	// Constructor / Destructor
	Bureaucrat (std::string name, int grade);
	Bureaucrat (const Bureaucrat &copy);
	~Bureaucrat ();

	// Getters
	std::string getName ();
	int getGrade ();

	// Grade changers
	void incrementGrade ();
	void decrementGrade ();

	// Sign Form
	void signForm (Form &form);

  private:
	// Private atributes
	const std::string _name;
	int _grade;

	// Private = operators
	Bureaucrat &operator= (const Bureaucrat &copy);
};

std::ostream &operator<< (std::ostream &, Bureaucrat &bureaucrat);

#endif
