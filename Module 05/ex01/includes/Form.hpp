#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <string>

class Bureaucrat;

class Form
{
  public:
	// Constructors and destructors
	Form (const std::string &name, const int grade_to_sign,
		  const int grade_to_exec);
	Form (const Form &copy);
	~Form ();

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
	Form &operator= (const Form &copy);
};

std::ostream &operator<< (std::ostream &outstream, Form &form);

#endif
