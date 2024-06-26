#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

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

	std::cout << std::endl << std::endl << std::endl ;

	const WrongAnimal *a = new WrongAnimal ();
	const WrongAnimal *b = new WrongDog ();
	const WrongAnimal *c = new WrongCat ();

	std::cout << b->getType () << " " << std::endl;
	std::cout << c->getType () << " " << std::endl;

	a->makeSound (); // will output the animal sound!
	b->makeSound ();
	c->makeSound ();

	delete(meta);
	delete(i);
	delete(j);
	delete(a);
	delete(b);
	delete(c);

	return 0;
}
