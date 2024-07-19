#include "Bureaucrat.hpp"
#include "Form.hpp"

void
test_construction ()
{
	int valid_number = ((MIN_GRADE + MAX_GRADE) / 2);

	Form A ("Form", valid_number, valid_number);
	std::cout << A;

	Bureaucrat God ("God all mighty", 1);
	A.beSigned (God);

	Form B (A);
	std::cout << B;

	Form C = A;
	std::cout << C;

	// Odd case because grades required to be signed/exec are constant
	Form D ("Form", 100, 100);
	D = A;
	std::cout << D;
}

void
test_forms (int grade_1, int grade_2)
{
	std::cout << std::endl;

	try
		{
			Form valid_form ("Form", grade_1, grade_2);
			std::cout << valid_form;
		}
	catch (const std::exception &e)
		{
			std::cerr << e.what () << std::endl;
		}
}

void
test_signatures ()
{
	std::cout << std::endl;

	Form form ("Form", 10, 10);
	Bureaucrat John ("John", 5);

	// Should be able to sign the form
	try
		{
			John.signForm (form);
		}
	catch (const std::exception &e)
		{
			std::cerr << e.what () << std::endl;
		}

	std::cout << std::endl;

	// Shouldn't be able to sign it the 2nd time around!
	try
		{
			John.signForm (form);
		}
	catch (const std::exception &e)
		{
			std::cerr << e.what () << std::endl;
		}

	std::cout << std::endl;

	// Shouldn't be able to sign it due to insuficient privilleges
	Form form_2 ("Form_2", 10, 10);
	Bureaucrat Steve ("Steve", 30);

	try
		{
			Steve.signForm (form_2);
		}
	catch (const std::exception &e)
		{
			std::cerr << e.what () << std::endl;
		}

	// Should be able to sign them after enough increments
	for (int i = 30; i > 10; i--)
		Steve.incrementGrade ();

	try
		{
			Steve.signForm (form_2);
		}
	catch (const std::exception &e)
		{
			std::cerr << e.what () << std::endl;
		}
}

int
main (void)
{
	// Tests correct construction, copy construction and destructor
	test_construction ();

	// Tests correct throw errors depending on values
	int valid_value = (MIN_GRADE + MAX_GRADE) / 2;
	test_forms (valid_value, valid_value);
	test_forms (MIN_GRADE + 1, valid_value);
	test_forms (valid_value, MIN_GRADE + 1);
	test_forms (MAX_GRADE - 1, valid_value);
	test_forms (valid_value, MAX_GRADE - 1);

	// Tests correct signatures
	test_signatures ();
}
