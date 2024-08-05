#include "RPN.hpp"
#include <iostream>
#include <sstream>

RPN::RPN () {}

RPN::RPN (const RPN &copy) { *this = copy; }

const RPN &
RPN::operator= (const RPN &copy)
{
	(void)copy;
	return *this;
}

RPN::~RPN () {}

void
RPN::perform_operation (std::stack<int> &stack, char buffer)
{
	int number_1;
	int number_2;

	number_2 = stack.top ();
	stack.pop ();

	number_1 = stack.top ();
	stack.pop ();

	int result;

	switch (buffer)
		{
		case ('+'):
			result = number_1 + number_2;
			break;
		case ('-'):
			result = number_1 - number_2;
			break;
		case ('*'):
			result = number_1 * number_2;
			break;
		case ('/'):
			result = number_1 / number_2;
			break;
		}

	stack.push (result);
}

int
RPN::calculate (const char *input)
{
	std::stringstream ss (input);
	std::string buffer;
	std::stack<int> stack;

	while (ss >> buffer)
		{
			if (buffer.length () != 1)
				return error_log ();

			if (is_number (buffer[0]))
				stack.push (buffer[0] - '0');
			else if (is_operator (buffer[0]) && stack.size () >= 2)
				perform_operation (stack, buffer[0]);
			else
				return error_log ();
		}

	if (stack.size () != 1)
		return error_log ();

	std::cout << stack.top () << std::endl;

	return 0;
}

bool
RPN::is_number (const char substring)
{
	return (substring >= '0' && substring <= '9');
}

bool
RPN::is_operator (const char substring)
{
	return (substring == '+' || substring == '-' || substring == '*'
			|| substring == '/');
}

int
RPN::error_log ()
{
	std::cout << "Error: invalid input" << std::endl;

	return 1;
}
