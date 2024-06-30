#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <string>

class Form
{
  public:
	// Exceptions
	class GradeTooHighException : public std::exception
	{
	  public:
		const std::string &GradeTooHighMessage ();
	};

	class GradeTooLowException : public std::exception
	{
	  public:
		const std::string &GradeTooLowMessage ();
	};

	// Constructors and destructors
	Form (const std::string &name, const int grade_to_sign,
		  const int grade_to_exec);
	Form (const Form &copy);
	~Form ();

	// Getters
	const std::string &get_name ();
	bool &get_signed_status();
	const int &get_grade_required_to_sign ();
	const int &get_grade_required_to_exec ();

	// Form actions
	void beSigned (Bureaucrat &nureaucrat);
	void signForm (Bureaucrat &nureaucrat);

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
