#include "Bureaucrat.hpp"

void
test_constructors ()
{
	std::string A = "A";

	Bureaucrat a (A, 1);
	std::cout << a;

	Bureaucrat b (a);
	std::cout << b;

	Bureaucrat c = a;
	std::cout << c;

	// Won't work because = operator is private
	/* 	Bureaucrat d (A, 0);
		d = a;
		std::cout << d; */
}

void
attempt_to_create_bureaucrat (const std::string &name, int grade)
{
	std::cout << std::endl;

	try
		{
			Bureaucrat Guy (name, grade);
			std::cout << Guy;
		}
	catch (const std::exception &exception_class)
		{
			std::cout << "Exception caught: " << exception_class.what ()
					  << std::endl;
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
			catch (const std::exception &exception_class)
				{
					std::cout
						<< "Exception caught: " << exception_class.what ()
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
			catch (const std::exception &exception_class)
				{
					std::cout
						<< "Exception caught: " << exception_class.what ()
						<< std::endl;
					return;
				}
		}
}

int
main (void)
{
	test_constructors ();

	attempt_to_create_bureaucrat ("Steven", MAX_GRADE);
	attempt_to_create_bureaucrat ("Richard", MIN_GRADE);
	attempt_to_create_bureaucrat ("Anderson", (MAX_GRADE + MIN_GRADE) / 2);
	attempt_to_create_bureaucrat ("Joseph", MAX_GRADE - 1);
	attempt_to_create_bureaucrat ("Amanda", MIN_GRADE + 1);

	attempt_invalid_increment ("Joe");
	attempt_invalid_decrement ("Donald");
}
