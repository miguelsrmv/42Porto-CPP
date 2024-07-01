#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		// Constructors and Destructors
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();
	
		// Execute function
		void execute(Bureaucrat const& executor) const;
	
	private:
		std::string _target;
		PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
};

#endif
