#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <time.h>
#include <unistd.h>

Base *
generate (void)
{
	usleep (100);
	switch (rand () % 3)
		{
		case 1:
			return new A;
		case 2:
			return new B;
		default:
			return new C;
		}
}

void
identify (Base *p)
{
	std::cout << "Base *p is of class ";

	if (dynamic_cast<A *> (p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *> (p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *> (p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown" << std::endl;
}

void
identify (Base &p)
{
	std::cout << "Base_reference &p is of class ";

	try
		{
			(void)dynamic_cast<A &> (p);
			std::cout << "A" << std::endl;
			return;
		}
	catch (const std::exception &e)
		{
		}
	try
		{
			(void)dynamic_cast<B &> (p);
			std::cout << "B" << std::endl;
			return;
		}
	catch (const std::exception &e)
		{
		};
	try
		{
			(void)dynamic_cast<C &> (p);
			std::cout << "C" << std::endl;
			return;
		}
	catch (const std::exception &e)
		{
		};
	std::cout << "unknown" << std::endl;
}

int
main (void)
{
	srand (time (NULL));

	for (int i = 0; i < 50; i++)
		{
			Base *ptr = generate ();
			Base &ref = *ptr;

			identify (ptr);
			identify (ref);

			delete ptr;
			std::cout << std::endl;
		}
	return (0);
}
