#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <unistd.h>

Base *generate(void)
{
	usleep(100);
	switch (rand() % 3)
	{
	case 1:
		return new A;
	case 2:
		return new B;
	default:
		return new C;
	}
}

void identify(Base *p)
{
	std::cout << "Base *p is of class ";

	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown" << std::endl;
}

void identify(Base &p)
{
	std::cout << "Base_reference &p is of class ";

	if (dynamic_cast<A *>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(&p))
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown" << std::endl;
}

int main(void)
{
	srand(time(NULL));

	for (int i = 0; i < 50; i++)
	{
		Base *ptr = generate();
		Base &ref = *ptr;

		identify(ptr);
		identify(ref);

		delete ptr;
		std::cout << std::endl;
	}
	return (0);
}
