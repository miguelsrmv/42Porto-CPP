#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <sys/stat.h>

class ShrubberyCreationForm : public AForm
{
  public:
	// Constructors and Destructors
	ShrubberyCreationForm (const std::string &target);
	ShrubberyCreationForm (const ShrubberyCreationForm &copy);
	ShrubberyCreationForm &operator= (const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm ();

	// Execute function
	void execute (void) const;

  private:
	std::string _target;
};

#endif
