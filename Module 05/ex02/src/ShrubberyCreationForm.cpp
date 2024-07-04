#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Parametrized ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), _target(copy._target)
{
	std::cout << "Copy ShrubberyCreationForm constructor called" << std::endl ;

	*this = copy;
}

ShrubberyCreationForm&
ShrubberyCreationForm::operator =(const ShrubberyCreationForm& copy)
{
	(void)copy;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Default ShrubberyCreationForm destructor called" << std::endl;
}

void
ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (((Bureaucrat &)executor).getGrade() > this->get_grade_required_to_exec())
	{
		throw AForm::GradeTooHighException ();
	}
	else if (!this->get_signed_status())
	{
		throw AForm::FormNotSignedException ();
	}
	else
	{
		std::string filename(_target + "_shrubbery");

		std::ofstream outfile;

		outfile.open(filename.c_str(), std::ios::out | std::ios::trunc);
		if (!outfile.is_open())
			std::cout << "Couldn't open up file!" << std::endl;
	
		outfile << "                                              .    " << "\n";
		outfile << "                                   .         ;     " << "\n";
		outfile << "      .              .              ;%     ;;      " << "\n";
		outfile << "        ,           ,                :;%  %;       " << "\n";
		outfile << "         :         ;                   :;%;'     .," << "\n";
		outfile << ",.        %;     %;            ;        %;'    ,;  " << "\n";
		outfile << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'   " << "\n";
		outfile << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'    " << "\n";
		outfile << "    ;%;      %;        ;%;        % ;%;  ,%;'      " << "\n";
		outfile << "     `%;.     ;%;     %;'         `;%%;.%;'        " << "\n";
		outfile << "      `:;%.    ;%%. %@;        %; ;@%;%'           " << "\n";
		outfile << "         `:%;.  :;bd%;          %;@%;'             " << "\n";
		outfile << "           `@%:.  :;%.         ;@@%;'              " << "\n";
		outfile << "             `@%.  `;@%.      ;@@%;                " << "\n";
		outfile << "               `@%%. `@%%    ;@@%;                 " << "\n";
		outfile << "                 ;@%. :@%%  %@@%;                  " << "\n";
		outfile << "                   %@bd%%%bd%%:;                   " << "\n";
		outfile << "                     #@%%%%%:;;                    " << "\n";
		outfile << "                     %@@%%%::;                     " << "\n";
		outfile << "                     %@@@%(o);  . '                " << "\n";
		outfile << "                     %@@@o%;:(.,'                  " << "\n";
		outfile << "                 `.. %@@@o%::;                     " << "\n";
		outfile << "                    `)@@@o%::;                     " << "\n";
		outfile << "                     %@@(o)::;                     " << "\n";
		outfile << "                    .%@@@@%::;                     " << "\n";
		outfile << "                    ;%@@@@%::;.                    " << "\n";
		outfile << "                   ;%@@@@%%:;;;.                   " << "\n";
		outfile << "               ...;%@@@@@%%:;;;;,..                " << "\n";
	}
}
