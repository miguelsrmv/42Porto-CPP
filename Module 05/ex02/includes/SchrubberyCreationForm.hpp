#ifndef SCHRUBBERY_CREATION_FORM_HPP
#define SCHRUBBERY_CREATION_FORM_HPP
#include "AForm.hpp"

class SchrubberyCreationForm : public AForm
{
	public:
		// Constructors and Destructors
		SchrubberyCreationForm(std::string& target);
		SchrubberyCreationForm(const SchrubberyCreationForm& copy);
		~SchrubberyCreationForm();
	
		// Execute function
		void execute(Bureaucrat const& executor) const;
	
	private:
		std::string _target;
		SchrubberyCreationForm& operator=(const SchrubberyCreationForm& copy);
};

#endif
