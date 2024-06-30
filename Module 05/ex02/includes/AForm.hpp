#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <string>

class Bureaucrat;

class AForm
{
  public:
	// Constructors and destructors
	AForm (const std::string &name);
	AForm (const AForm &copy);
	virtual ~AForm ();

	// Getters
	const std::string &get_name ();
	bool &get_signed_status ();
	const int &get_grade_required_to_sign ();
	const int &get_grade_required_to_exec ();

	// Form actions
	void beSigned (Bureaucrat &bureaucrat);

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

  private:
	const std::string form_name;
	bool signed_status;
	const int grade_required_to_sign;
	const int grade_required_to_exec;

	// Copy constructor and = assignment
	AForm &operator= (const AForm &copy);
};

std::ostream &operator<< (std::ostream &outstream, AForm &form);

#endif
