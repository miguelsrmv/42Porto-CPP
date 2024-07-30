#include "Span.hpp"
#include <cctype>
#include <cstring>
#include <iostream>

int
constructor_test ()
{
	std::cout << "Constructor test" << std::endl;
	Span sp = Span (3);
	sp.addNumber (1);
	// Should print {1}
	std::cout << sp;

	std::cout << "Assignment operator test" << std::endl;
	Span sp2 = sp;
	sp.addNumber (2);
	sp2.addNumber (3);
	// Should print {1, 2}
	std::cout << sp;
	// Should print {1, 3}
	std::cout << sp2;

	std::cout << "Copy constructor test" << std::endl;
	Span sp3 (sp);
	sp.addNumber (3);
	sp3.addNumber (4);
	// Should print {1, 2, 3}
	std::cout << sp;
	// Should print {1, 2, 4}
	std::cout << sp3 << std::endl;

	return 0;
}

int
subject_test ()
{
	std::cout << "Subject test" << std::endl;
	Span sp = Span (5);
	sp.addNumber (6);
	sp.addNumber (3);
	sp.addNumber (17);
	sp.addNumber (9);
	sp.addNumber (11);
	std::cout << sp.shortestSpan () << std::endl;
	std::cout << sp.longestSpan () << std::endl;
	std::cout << sp << std::endl;

	return 0;
}

int
test_empty_span ()
{
	std::cout << "Empty span test" << std::endl;

	Span sp = Span (5);
	try
		{
			std::cout << sp.shortestSpan () << std::endl;
		}
	catch (std::exception &e)
		{
			std::cout << e.what () << std::endl;
		}
	try
		{
			std::cout << sp.longestSpan () << std::endl;
		}
	catch (std::exception &e)
		{
			std::cout << e.what () << std::endl;
		}
	std::cout << sp;

	sp.addNumber (-1);
	try
		{
			std::cout << sp.shortestSpan () << std::endl;
		}
	catch (std::exception &e)
		{
			std::cout << e.what () << std::endl;
		}
	try
		{
			std::cout << sp.longestSpan () << std::endl;
		}
	catch (std::exception &e)
		{
			std::cout << e.what () << std::endl;
		}
	std::cout << sp;

	sp.addNumber (-2);
	try
		{
			std::cout << sp.shortestSpan () << std::endl;
		}
	catch (std::exception &e)
		{
			std::cout << e.what () << std::endl;
		}
	try
		{
			std::cout << sp.longestSpan () << std::endl;
		}
	catch (std::exception &e)
		{
			std::cout << e.what () << std::endl;
		}
	std::cout << sp;

	return (0);
}

int
test_full_span ()
{
	std::cout << "Full span test" << std::endl;
	Span sp = Span (3);
	for (int i = 0; i <= 3; i++)
		{
			try
				{
					sp.addNumber (i);
				}
			catch (std::exception &e)
				{
					std::cout << e.what () << std::endl;
				}
		}

	std::cout << sp;

	return (0);
}

int
fill_everything_test ()
{
	std::cout << "Fill everything test" << std::endl;
	Span sp = Span (20);
	sp.addNumber (1);
	sp.addNumber (2);
	sp.addNumber (3);
	sp.fill_in_span ();

	std::cout << sp.shortestSpan () << std::endl;
	std::cout << sp.longestSpan () << std::endl;
	std::cout << sp << std::endl;

	return (0);
}

int
massive_test ()
{
	std::cout << "Massive test" << std::endl;
	Span sp = Span (10000);
	sp.fill_in_span ();

	std::cout << sp.shortestSpan () << std::endl;
	std::cout << sp.longestSpan () << std::endl;
	std::cout << sp << std::endl;

	return (0);
}

int
main (int argc, char **argv)
{
	if (argc != 2)
		return (1);

	std::string arg = argv[1];

	if (arg.length () != 1 || !isdigit (arg[0]))
		return (1);

	switch (arg[0] - '0')
		{
		case 1:
			return constructor_test ();
		case 2:
			return subject_test ();
		case 3:
			return test_empty_span ();
		case 4:
			return test_full_span ();
		case 5:
			return fill_everything_test ();
		case 6:
			return massive_test ();
		default:
			return (1);
		}
	
	return (0);
}
