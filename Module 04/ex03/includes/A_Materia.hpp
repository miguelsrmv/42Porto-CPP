#ifndef A_MATERIA
#define A_MATERIA

#include "I_Character.hpp"
#include <string>

class AMateria
{
  protected:
	// [...]

  public:
	AMateria (std::string const &type);
	// [...]
	std::string const &getType () const; // Returns the materia type
	virtual AMateria *clone () const = 0;
	virtual void use (ICharacter &target);
};

#endif