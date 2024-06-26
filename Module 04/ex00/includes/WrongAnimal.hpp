#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
  public:
	WrongAnimal ();
	WrongAnimal (const WrongAnimal &copy);
	WrongAnimal &operator= (const WrongAnimal &copy);
	virtual ~WrongAnimal ();

	void makeSound () const;

	std::string getType () const;

  protected:
	std::string type;
};

#endif
