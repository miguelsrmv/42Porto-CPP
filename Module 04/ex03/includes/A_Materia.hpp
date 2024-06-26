#ifndef A_MATERIA
#define A_MATERIA

#include "I_Character.hpp"
#include <iostream>
#include <string>

class AMateria
{
  protected:
	std::string _materia_type;

  public:
	AMateria ();
	AMateria (std::string const &type);
	AMateria (const AMateria &copy);
	AMateria &operator= (const AMateria &copy);
	virtual ~AMateria ();

	std::string const &getType () const; // Returns the materia type
	virtual AMateria *clone () const = 0;
	virtual void use (ICharacter &target);
};

#endif
