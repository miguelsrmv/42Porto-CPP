#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		// Constructors and Destructors
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();
	
		// Execute function
		void execute(Bureaucrat const& executor) const;
	
	private:
		std::string _target;
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
};



#endif
