#include "SchrubberyCreationForm.hpp"

SchrubberyCreationForm::SchrubberyCreationForm(std::string& target) : AForm("SchrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Parametrized constructor called" << std::endl;
}

SchrubberyCreationForm::SchrubberyCreationForm(const SchrubberyCreationForm& copy) : AForm(copy), _target(copy._target)
{
	std::cout << "Copy constructor called" << std::endl ;

	*this = copy;
}

SchrubberyCreationForm&
SchrubberyCreationForm::operator =(const SchrubberyCreationForm& copy)
{
	(void)copy;
	return (*this);
}

SchrubberyCreationForm::~SchrubberyCreationForm()
{
	std::cout << "Default destructor called" << std::endl;
}

void
SchrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (((Bureaucrat &)executor).getGrade() > this->get_grade_required_to_exec())
	{
		throw AForm::GradeTooHighException ();
	}
	else if (!this->get_signed_status())
	{

	}
	else
	{
		return ;
	}
}
