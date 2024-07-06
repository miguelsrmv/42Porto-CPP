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
	AForm (const std::string &name, int sign_grade, int exec_grade);
	AForm (const AForm &copy);
	virtual ~AForm ();

	// Getters
	const std::string &get_name () const;
	bool get_signed_status () const;
	int get_grade_required_to_sign () const;
	int get_grade_required_to_exec () const;

	// Form actions
	void beSigned (Bureaucrat &bureaucrat);
	void execute (Bureaucrat const &executor) const;
	virtual void execute (void) const = 0;

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

	class FormNotSignedException : public std::exception
	{
	  public:
		const char *what () const throw ();
	};

  private:
	const std::string _form_name;
	bool _signed_status;
	const int _grade_required_to_sign;
	const int _grade_required_to_exec;

	// Copy constructor and = assignment
	AForm &operator= (const AForm &copy);
};

std::ostream &operator<< (std::ostream &outstream, const AForm &form);

#endif
