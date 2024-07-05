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
ShrubberyCreationForm::execute(void) const
{
	std::string filename(_target + "_shrubbery");
	std::ofstream outfile;

	outfile.open(filename.c_str(), std::ios::out | std::ios::trunc);
	if (!outfile.is_open())
		std::cout << "Couldn't open up file!" << std::endl;

	outfile << "                                              .    " << std::endl;
	outfile << "                                   .         ;     " << std::endl;
	outfile << "      .              .              ;%     ;;      " << std::endl;
	outfile << "        ,           ,                :;%  %;       " << std::endl;
	outfile << "         :         ;                   :;%;'     .," << std::endl;
	outfile << ",.        %;     %;            ;        %;'    ,;  " << std::endl;
	outfile << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'   " << std::endl;
	outfile << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'    " << std::endl;
	outfile << "    ;%;      %;        ;%;        % ;%;  ,%;'      " << std::endl;
	outfile << "     `%;.     ;%;     %;'         `;%%;.%;'        " << std::endl;
	outfile << "      `:;%.    ;%%. %@;        %; ;@%;%'           " << std::endl;
	outfile << "         `:%;.  :;bd%;          %;@%;'             " << std::endl;
	outfile << "           `@%:.  :;%.         ;@@%;'              " << std::endl;
	outfile << "             `@%.  `;@%.      ;@@%;                " << std::endl;
	outfile << "               `@%%. `@%%    ;@@%;                 " << std::endl;
	outfile << "                 ;@%. :@%%  %@@%;                  " << std::endl;
	outfile << "                   %@bd%%%bd%%:;                   " << std::endl;
	outfile << "                     #@%%%%%:;;                    " << std::endl;
	outfile << "                     %@@%%%::;                     " << std::endl;
	outfile << "                     %@@@%(o);  . '                " << std::endl;
	outfile << "                     %@@@o%;:(.,'                  " << std::endl;
	outfile << "                 `.. %@@@o%::;                     " << std::endl;
	outfile << "                    `)@@@o%::;                     " << std::endl;
	outfile << "                     %@@(o)::;                     " << std::endl;
	outfile << "                    .%@@@@%::;                     " << std::endl;
	outfile << "                    ;%@@@@%::;.                    " << std::endl;
	outfile << "                   ;%@@@@%%:;;;.                   " << std::endl;
	outfile << "               ...;%@@@@@%%:;;;;,..                " << std::endl;
}
