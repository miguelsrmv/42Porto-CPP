#ifndef INTERN_HPP
#define INTERN_hpp

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
  public:
	Intern ();
	Intern (const Intern &copy);
	const Intern &operator= (const Intern &copy);
	~Intern ();

	AForm *makeForm (const std::string &form_name, const std::string &form_target) const;

  private:
	AForm *createPresidentialPardornForm (const std::string &target) const;
	AForm *createRobotomyRequestForm (const std::string &target) const;
	AForm *createShrubberyCreationForm (const std::string &target) const;
};

#endif