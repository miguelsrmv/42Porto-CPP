#include "Bureaucrat.hpp"

void
attempt_to_create_bureaucrat (const std::string &name, int grade)
{
	std::cout << std::endl;

	try
		{
			Bureaucrat Guy (name, grade);
			std::cout << Guy;
		}
	catch (const Bureaucrat::GradeTooHighException &exception_class)
		{
			std::cout << "Exception caught: "
					  << exception_class.too_high_message () << std::endl;
		}
	catch (const Bureaucrat::GradeTooLowException &exception_class)
		{
			std::cout << "Exception caught: "
					  << exception_class.too_low_message () << std::endl;
		}
}

void
attempt_invalid_increment (const std::string &name)
{
	std::cout << std::endl;

	Bureaucrat Guy (name, MAX_GRADE + 1);

	for (int i = MAX_GRADE; i < MIN_GRADE; i++)
		{
			std::cout << Guy;

			try
				{
					Guy.incrementGrade ();
				}
			catch (const Bureaucrat::GradeTooHighException &exception_class)
				{
					std::cout << "Exception caught: "
							  << exception_class.too_high_message ()
							  << std::endl;
					return;
				}
			catch (const Bureaucrat::GradeTooLowException &exception_class)
				{
					std::cout << "Exception caught: "
							  << exception_class.too_low_message ()
							  << std::endl;
					return;
				}
		}
}

void
attempt_invalid_decrement (const std::string &name)
{
	std::cout << std::endl;

	Bureaucrat Guy (name, MIN_GRADE - 1);

	for (int i = MAX_GRADE; i < MIN_GRADE; i++)
		{
			std::cout << Guy;
			try
				{
					Guy.decrementGrade ();
				}
			catch (const Bureaucrat::GradeTooHighException &exception_class)
				{
					std::cout << "Exception caught: "
							  << exception_class.too_high_message ()
							  << std::endl;
					return;
				}
			catch (const Bureaucrat::GradeTooLowException &exception_class)
				{
					std::cout << "Exception caught: "
							  << exception_class.too_low_message ()
							  << std::endl;
					return;
				}
		}
}

int
main (void)
{
	attempt_to_create_bureaucrat ("Steven", MAX_GRADE);
	attempt_to_create_bureaucrat ("Richard", MIN_GRADE);
	attempt_to_create_bureaucrat ("Anderson", (MAX_GRADE + MIN_GRADE) / 2);
	attempt_to_create_bureaucrat ("Joseph", MAX_GRADE - 1);
	attempt_to_create_bureaucrat ("Amanda", MIN_GRADE + 1);

	attempt_invalid_increment ("Joe");
	attempt_invalid_decrement ("Donald");
}
