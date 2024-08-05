#include "RPN.hpp"
#include <iostream>

RPN::RPN () {}

RPN::RPN (const RPN &copy) { *this = copy; }

const RPN &
RPN::operator= (const RPN &copy)
{
	(void)copy;
	return *this;
}

RPN::~RPN () {}

int
RPN::calculate (const char *input)
{
	std::cout << input << std::endl;

	return (1);
}
