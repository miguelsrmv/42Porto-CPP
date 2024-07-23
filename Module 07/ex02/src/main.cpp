#include "Array.hpp"
#include <iostream>
#include <sstream>

void
testDefaultConstructor (void)
{
	std::cout << std::endl
			  << "======= Testing Array Default Constructor ======="
			  << std::endl;

	Array<int> numbers (10);

	for (size_t i = 0; i < numbers.size (); i++)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
}

void
testAssignmentOperator (void)
{
	std::cout << std::endl
			  << "======= Testing Array Assisgnment Operator ======= "
			  << std::endl;

	Array<int> numbers (10);

	for (size_t i = 0; i < numbers.size (); i++)
		numbers[i] = 42 + i;

	Array<int> copy (numbers);

	for (size_t i = 0; i < copy.size (); i++)
		numbers[i] = 42 - i;

	for (size_t i = 0; i < copy.size (); i++)
		{
			std::cout << "Numbers[" << i << "] = " << numbers[i] << " vs Copy["
					  << i << "] = " << copy[i] << std::endl;
		}
}

void
testCopyConstructor (void)
{
	std::cout << std::endl
			  << "======= Testing Copy Constructor ======= " << std::endl;

	Array<int> numbers (10);
	Array<int> copy (5);

	for (size_t i = 0; i < numbers.size (); i++)
		numbers[i] = 42 + i;

	copy = numbers;

	for (size_t i = 0; i < copy.size (); i++)
		numbers[i] = 42 - i;

	for (size_t i = 0; i < copy.size (); i++)
		{
			std::cout << "Numbers[" << i << "] = " << numbers[i] << " vs Copy["
					  << i << "] = " << copy[i] << std::endl;
		}
}

void
testOutOfBoundsIndexes (void)
{
	std::cout << std::endl
			  << "======= Testing Array Invalid Index =======" << std::endl;
	Array<int> numbers (10);

	try
		{
			numbers[-1] = 0;
		}
	catch (const std::exception &e)
		{
			std::cout << e.what () << std::endl;
		}

	try
		{
			numbers[10] = 0;
		}
	catch (const std::exception &e)
		{
			std::cout << e.what () << std::endl;
		}
}

int
main (void)
{
	testDefaultConstructor ();
	testAssignmentOperator ();
	testCopyConstructor ();
	testOutOfBoundsIndexes ();
	return 0;
}
