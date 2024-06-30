#include "Cat.hpp"
#include "Dog.hpp"

void
test_animal_creation ()
{
	Animal *animal_array[10];

	for (int i = 0; i < 10; i++)
		{
			std::cout << "(" << i << ")" << std::endl;
			if (i % 2)
				animal_array[i] = new Dog;
			else
				animal_array[i] = new Cat;
		}

	for (int i = 0; i < 10; i++)
		{
			std::cout << "(" << i << ")" << std::endl;
			animal_array[i]->makeSound ();
		}

	for (int i = 0; i < 10; i++)
		{
			std::cout << "(" << i << ")" << std::endl;
			delete (animal_array[i]);
		}
}

void
test_animal_copies ()
{

	std::cout << std::endl;

	Dog dog;
	{
		Dog tmp_dog = dog;
	}

	std::cout << std::endl;

	Dog *dog_ptr = new Dog ();
	{
		Dog *tmp_dog_2 = new Dog (*dog_ptr);
		delete (tmp_dog_2);
	}
	delete (dog_ptr);

	std::cout << std::endl;

	Cat cat;
	{
		Cat tmp_cat = cat;
	}

	std::cout << std::endl;

	Cat *cat_ptr = new Cat ();
	{
		Cat *tmp_cat_2 = new Cat (*cat_ptr);
		delete (tmp_cat_2);
	}
	delete (cat_ptr);

	std::cout << std::endl;
}

int
main (void)
{
	test_animal_creation ();
	test_animal_copies ();

	return (0);
}
