#ifndef A_ANIMAL_HPP
#define A_ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
  public:
	Animal ();
	Animal (const Animal &copy);
	Animal &operator= (const Animal &copy);
	virtual ~Animal ();

	virtual void makeSound () const = 0;

	std::string getType () const;

  protected:
	std::string type;
};

#endif
