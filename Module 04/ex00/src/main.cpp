#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

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

void
test_wrong_animal_copies ()
{

	std::cout << std::endl;

	WrongDog dog;
	{
		WrongDog tmp_dog = dog;
	}

	std::cout << std::endl;

	WrongDog *dog_ptr = new WrongDog ();
	{
		WrongDog *tmp_dog_2 = new WrongDog (*dog_ptr);
		delete (tmp_dog_2);
	}
	delete (dog_ptr);

	std::cout << std::endl;

	WrongCat cat;
	{
		WrongCat tmp_cat = cat;
	}

	std::cout << std::endl;

	WrongCat *cat_ptr = new WrongCat ();
	{
		WrongCat *tmp_cat_2 = new WrongCat (*cat_ptr);
		delete (tmp_cat_2);
	}
	delete (cat_ptr);

	std::cout << std::endl;
}

int
main (void)
{
	const Animal *meta = new Animal ();
	const Animal *j = new Dog ();
	const Animal *i = new Cat ();

	std::cout << j->getType () << " " << std::endl;
	std::cout << i->getType () << " " << std::endl;

	i->makeSound (); // will output the cat sound!
	j->makeSound ();
	meta->makeSound ();

	std::cout << std::endl;

	const WrongAnimal *a = new WrongAnimal ();
	const WrongAnimal *b = new WrongDog ();
	const WrongAnimal *c = new WrongCat ();
	const WrongCat *d = new WrongCat ();
	const WrongDog *e = new WrongDog ();

	std::cout << b->getType () << " " << std::endl;
	std::cout << c->getType () << " " << std::endl;

	a->makeSound (); // will output the animal sound!
	b->makeSound ();
	c->makeSound ();
	d->makeSound (); // will output cat sound because it's a wrongcat pointer
	e->makeSound (); // will output dog sound because it's a wrongdog pointer

	std::cout << std::endl;

	delete (meta);
	delete (i);
	delete (j);
	delete (a);
	delete (b);
	delete (c);
	delete (d);
	delete (e);

	test_animal_copies ();
	test_wrong_animal_copies ();

	return 0;
}
