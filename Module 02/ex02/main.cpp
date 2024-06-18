#include "Fixed.hpp"

void
test_increments (void)
{
	Fixed a;
	const Fixed b (Fixed (5.05f) * Fixed (2));
	const Fixed c (Fixed (5.05f) + Fixed (2));

	std::cout << "\n\t--- Testing increments ---\n" << std::endl;
	std::cout << "The value of a is: " << a << std::endl;
	std::cout << "The value of ++a is: " << ++a << std::endl;
	std::cout << "The value of a is: " << a << std::endl;
	std::cout << "The value of a++ is: " << a++ << std::endl;
	std::cout << "The value of a is: " << a << std::endl;
	std::cout << "The value of b is: " << b << std::endl;
	std::cout << "The value of c is: " << c << std::endl;
	std::cout << "The maximum between a and b is: " << Fixed::max (a, b)
			  << std::endl;
}

void
test_decrements (void)
{
	Fixed a;
	const Fixed b (Fixed (5.05f) / Fixed (2));
	const Fixed c (Fixed (5.05f) - Fixed (2));

	std::cout << "\n\t--- Testing decrements ---\n" << std::endl;
	std::cout << "The value of a is: " << a << std::endl;
	std::cout << "The value of --a is: " << --a << std::endl;
	std::cout << "The value of a is: " << a << std::endl;
	std::cout << "The value of a-- is: " << a-- << std::endl;
	std::cout << "The value of a is: " << a << std::endl;
	std::cout << "The value of b is: " << b << std::endl;
	std::cout << "The value of c is: " << c << std::endl;
	std::cout << "The minimum between a and b is: " << Fixed::min (a, b)
			  << std::endl;
}

void
test_comparisons (void)
{
	Fixed a (-5.5f);
	Fixed b (5.0f);

	std::cout << "\n\t--- Testing comparison ---\n" << std::endl;

	if (a != b)
		std::cout << "A(" << a << ") != B(" << b << ")" << std::endl;
	else
		std::cout << "A(" << a << ") == B(" << b << ")" << std::endl;
	if (a > b)
		std::cout << "A(" << a << ") > B(" << b << ")" << std::endl;
	if (a < b)
		std::cout << "A(" << a << ") < B(" << b << ")" << std::endl;
	if (a >= b)
		std::cout << "A(" << a << ") >= B(" << b << ")" << std::endl;
	if (a <= b)
		std::cout << "A(" << a << ") <= B(" << b << ")" << std::endl;
}

int
main (void)
{
	Fixed a;
	Fixed const b (Fixed (5.05f) * Fixed (2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max (a, b) << std::endl;

	test_increments ();
	test_decrements ();
	test_comparisons ();
	return (0);
}

