#ifndef BREAUCRAT_HPP
#define BREAUCRAT_HPP

#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <string>

#define MIN_GRADE 150
#define MAX_GRADE 1

class AForm;

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
	const std::string& getName () const;
	int getGrade () const;

	// Grade changers
	void incrementGrade ();
	void decrementGrade ();

	// Sign Form
	void signForm (AForm &form);

	// Execute form
	void executeForm(AForm const &form);

  private:
	// Private atributes
	const std::string name;
	int grade;

	// Private = operators
	Bureaucrat &operator= (const Bureaucrat &copy);
};

std::ostream &operator<< (std::ostream &, Bureaucrat &bureaucrat);

#endif
