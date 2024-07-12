#include <string>
#include <iostream>

template <class T>
void swap(T* a, T* b)
{
	T temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

void test_swap()
{
	std::cout << "Testing with INTS" << std:: endl;
	int a = 1;
	int b = 2;
	std::cout << "a is " << a << " and b is " << b << std::endl;
	swap(&a, &b);
	std::cout << "a is " << a << " and b is " << b << std::endl;


	std::cout << "Testing with FLOATS" << std:: endl;
	float c = 10.0f;
	float d = 20.0f;
	std::cout << "c is " << c << " and d is " << d << std::endl;
	swap(&c, &d);
	std::cout << "c is " << a << " and d is " << d << std::endl;


	std::cout << "Testing with STRINGS" << std:: endl;
	std::string my_name("Miguel");
	std::string your_name("Jonhathan");
	std::cout << "My name is " << my_name << " and your name is " << your_name << std::endl;
	swap(&my_name, &your_name);
	std::cout << "My name is " << my_name << " and your name is " << your_name << std::endl;
}

void test_min()
{
	return ;
}

void test_max()
{
	return ;
}

int main(void)
{
	test_swap();
	test_min();
	test_max();
}

