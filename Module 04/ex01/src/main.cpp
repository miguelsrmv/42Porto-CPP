#include "Cat.hpp"
#include "Dog.hpp"

int
main (void)
{
	Animal *animal_array[100];

	for (int i = 0; i < 100; i++)
	{
		std::cout << "(" << i << ")" << std::endl ;
		if (i % 2)
			animal_array[i] = new Dog;
		else
			animal_array[i] = new Cat;
	}

	for (int i = 0; i < 100; i++)
	{
		std::cout << "(" << i << ")" << std::endl ;
		animal_array[i]->makeSound();
	}

	for (int i = 0; i < 100; i++)
	{
		std::cout << "(" << i << ")" << std::endl ;
		delete(animal_array[i]);
	}

	return 0;
}
