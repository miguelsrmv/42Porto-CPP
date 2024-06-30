#ifndef BREAUCRAT_HPP
#define BREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

#define MIN_GRADE 150
#define MAX_GRADE 1

class Bureaucrat
{
  public:
	// Exceptions
	class GradeTooHighException : public std::exception
	{
	  public:
		std::string too_high_message () const;
	};
	class GradeTooLowException : public std::exception
	{
	  public:
		std::string too_low_message () const;
	};

	// Constructor / Destructor
	Bureaucrat (std::string name, int grade);
	~Bureaucrat ();

	// Getters
	std::string getName ();
	int getGrade ();

	// Grade changers
	void incrementGrade ();
	void decrementGrade ();

  private:
	// Private atributes
	const std::string name;
	int grade;

	// Private copy constructor and = operators
	Bureaucrat (const Bureaucrat &copy);
	Bureaucrat &operator= (const Bureaucrat &copy);
};

std::ostream &operator<< (std::ostream &, Bureaucrat &bureaucrat);

#endif
