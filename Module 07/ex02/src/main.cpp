#include "Array.tpp"
#include <iostream>

void
test_int_array ()
{
	std::cout << "INT TESTING" << std::endl;

	// Default constructor
	std::cout << "Default constructor testing (shouldn't print anything)"
			  << std::endl;
	Array<int> no_number;
	for (size_t i = 0; i < no_number.size (); i++)
		std::cout << "numbers[" << i << "] = " << no_number[i] << std::endl;
	std::cout << std::endl;

	// Parametrized constructor
	std::cout << "Parametrized constructor testing (should print 0s)"
			  << std::endl;
	Array<int> numbers (10);
	for (size_t i = 0; i < numbers.size (); i++)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	std::cout << std::endl;

	// [] operator
	std::cout << "[] operator (should print squares)" << std::endl;
	for (size_t i = 0; i < numbers.size (); i++)
		numbers[i] = i * i;
	for (size_t i = 0; i < numbers.size (); i++)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	std::cout << std::endl;

	// Copy operator
	std::cout << "Copy constructor testing (should print the same)"
			  << std::endl;
	Array<int> copy (numbers);
	for (size_t i = 0; i < copy.size (); i++)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	std::cout << std::endl;

	// = Operator
	std::cout << "= operator testing (should print the same)" << std::endl;
	Array<int> equal_array = numbers;

	for (size_t i = 0; i < copy.size (); i++)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	std::cout << std::endl << std::endl;
}

void
test_float_array ()
{
	std::cout << "FLOAT TESTING" << std::endl;

	// Default constructor
	std::cout << "Default constructor testing (shouldn't print anything)"
			  << std::endl;
	Array<float> no_number;
	for (size_t i = 0; i < no_number.size (); i++)
		std::cout << "numbers[" << i << "] = " << no_number[i] << std::endl;
	std::cout << std::endl;

	// Parametrized constructor
	std::cout << "Parametrized constructor testing (should print 0s)"
			  << std::endl;
	Array<float> numbers (10);
	for (size_t i = 0; i < numbers.size (); i++)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	std::cout << std::endl;

	// [] operator
	std::cout << "[] operator (should print weird numbers)" << std::endl;
	for (size_t i = 0; i < numbers.size (); i++)
		numbers[i] = i * (i * 0.5);
	for (size_t i = 0; i < numbers.size (); i++)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	std::cout << std::endl;

	// Copy operator
	std::cout << "Copy constructor testing (should print the same)"
			  << std::endl;
	Array<float> copy (numbers);
	for (size_t i = 0; i < copy.size (); i++)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	std::cout << std::endl;

	// = Operator
	std::cout << "= operator testing (should print the same)" << std::endl;
	Array<float> equal_array = numbers;

	for (size_t i = 0; i < copy.size (); i++)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	std::cout << std::endl << std::endl;
}

void
test_string_array ()
{
	std::cout << "STRING TESTING" << std::endl;

	// Default constructor
	std::cout << "Default constructor testing (shouldn't print anything)"
			  << std::endl;
	Array<std::string> no_string;
	for (size_t i = 0; i < no_string.size (); i++)
		std::cout << "string[" << i << "] = " << no_string[i] << std::endl;
	std::cout << std::endl;

	// Parametrized constructor
	std::cout << "Parametrized constructor testing (should print nothing)"
			  << std::endl;
	Array<std::string> strings (3);
	for (size_t i = 0; i < strings.size (); i++)
		std::cout << "strings[" << i << "] = " << strings[i] << std::endl;
	std::cout << std::endl;

	// [] operator
	std::cout << "[] operator (should print new Names)" << std::endl;
	strings[0] = std::string ("Miguel");
	strings[1] = std::string ("João");
	strings[2] = std::string ("Zé");
	for (size_t i = 0; i < strings.size (); i++)
		std::cout << "string[" << i << "] = " << strings[i] << std::endl;
	std::cout << std::endl;

	// Copy operator
	std::cout << "Copy constructor testing (should print the same)"
			  << std::endl;
	Array<std::string> copy (strings);
	for (size_t i = 0; i < copy.size (); i++)
		std::cout << "string[" << i << "] = " << strings[i] << std::endl;
	std::cout << std::endl;

	// = operator
	std::cout << "= operator testing (should print the same)" << std::endl;
	Array<std::string> equal_array = strings;
	for (size_t i = 0; i < copy.size (); i++)
		std::cout << "string[" << i << "] = " << strings[i] << std::endl;
	std::cout << std::endl << std::endl;
}

int
main (void)
{
	test_int_array ();
	test_float_array ();
	test_string_array ();
}
