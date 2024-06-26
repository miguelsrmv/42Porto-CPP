#ifndef A_MATERIA
#define A_MATERIA

#include "I_Character.hpp"
#include <string>
#include <iostream>

class AMateria
{
  protected:
	std::string materia_type;

  public:
	AMateria ();
	AMateria (std::string const &type);
	AMateria (const AMateria& copy);
	AMateria &operator=(const AMateria& copy);
	~AMateria ();

	std::string const &getType () const; // Returns the materia type
	virtual AMateria *clone () const = 0;
	virtual void use (ICharacter &target);
};

#endif
