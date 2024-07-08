#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm (const std::string &target)
	: AForm ("ShrubberyCreationForm", 145, 137), _target (target)
{
	std::cout << "Parametrized ShrubberyCreationForm constructor called"
			  << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm (
	const ShrubberyCreationForm &copy)
	: AForm (copy), _target (copy._target)
{
	std::cout << "Copy ShrubberyCreationForm constructor called" << std::endl;

	*this = copy;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator= (const ShrubberyCreationForm &copy)
{
	// Unable to change parameters because they are private and there are no setters
	(void)copy;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm ()
{
	std::cout << "Default ShrubberyCreationForm destructor called"
			  << std::endl;
}

void
ShrubberyCreationForm::execute (void) const
{
	std::string filename (_target + "_shrubbery");
	std::ofstream outfile;

	// Tries to open file and see if it's openable
	outfile.open (filename.c_str (), std::ios::out | std::ios::trunc);
	if (!outfile.is_open ())
		std::cout << "Couldn't open up file!" << std::endl;

	// Checks if file happens to be a dir
	struct stat info;
    if (stat(filename.c_str(), &info) != 0)
	{
        std::cerr << "Cannot access " << filename << std::endl;
        return ; // Cannot access the file
    }
	if (info.st_mode & S_IFDIR)
		std::cout << "File is a directory!" << std::endl;

	// Prints to outfile stream
	outfile << "                                              .    "
			<< std::endl;
	outfile << "                                   .         ;     "
			<< std::endl;
	outfile << "      .              .              ;%     ;;      "
			<< std::endl;
	outfile << "        ,           ,                :;%  %;       "
			<< std::endl;
	outfile << "         :         ;                   :;%;'     .,"
			<< std::endl;
	outfile << ",.        %;     %;            ;        %;'    ,;  "
			<< std::endl;
	outfile << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'   "
			<< std::endl;
	outfile << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'    "
			<< std::endl;
	outfile << "    ;%;      %;        ;%;        % ;%;  ,%;'      "
			<< std::endl;
	outfile << "     `%;.     ;%;     %;'         `;%%;.%;'        "
			<< std::endl;
	outfile << "      `:;%.    ;%%. %@;        %; ;@%;%'           "
			<< std::endl;
	outfile << "         `:%;.  :;bd%;          %;@%;'             "
			<< std::endl;
	outfile << "           `@%:.  :;%.         ;@@%;'              "
			<< std::endl;
	outfile << "             `@%.  `;@%.      ;@@%;                "
			<< std::endl;
	outfile << "               `@%%. `@%%    ;@@%;                 "
			<< std::endl;
	outfile << "                 ;@%. :@%%  %@@%;                  "
			<< std::endl;
	outfile << "                   %@bd%%%bd%%:;                   "
			<< std::endl;
	outfile << "                     #@%%%%%:;;                    "
			<< std::endl;
	outfile << "                     %@@%%%::;                     "
			<< std::endl;
	outfile << "                     %@@@%(o);  . '                "
			<< std::endl;
	outfile << "                     %@@@o%;:(.,'                  "
			<< std::endl;
	outfile << "                 `.. %@@@o%::;                     "
			<< std::endl;
	outfile << "                    `)@@@o%::;                     "
			<< std::endl;
	outfile << "                     %@@(o)::;                     "
			<< std::endl;
	outfile << "                    .%@@@@%::;                     "
			<< std::endl;
	outfile << "                    ;%@@@@%::;.                    "
			<< std::endl;
	outfile << "                   ;%@@@@%%:;;;.                   "
			<< std::endl;
	outfile << "               ...;%@@@@@%%:;;;;,..                "
			<< std::endl;
}
