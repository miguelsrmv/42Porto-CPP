#ifndef CAT_HPP
#define CAT_HPP

#include "A_Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
  public:
	Cat ();
	Cat (const Cat &copy);
	Cat &operator= (const Cat &copy);
	~Cat ();

	void makeSound () const;

  private:
	Brain *animal_brain;
};

#endif
