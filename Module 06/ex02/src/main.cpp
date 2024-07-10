#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>

Base * generate(void)
{
	switch(rand() % 3)
	{
		case 1:
			return new class_A;
		case 2:
			return new class_B;
		case 3:
			return new class_C;
	}
}

void identify(Base* p);

void identify(Base& p);

int main(void)
{
	A class_A;
	B class_B;
	C class_C;
	Base class_Base;

	(void)class_A;
	(void)class_B;
	(void)class_C;
	(void)class_Base;
}

