#ifndef CURE_MATERIA_HPP
#define CURE_MATERIA_HPP

#include "A_Materia.hpp"

class Cure_Materia : public AMateria
{
  public:
	Cure_Materia ();
	Cure_Materia (const Cure_Materia& copy);
	Cure_Materia &operator=(const Cure_Materia& copy);
	~Cure_Materia ();

	Cure_Materia *clone () const;
	void use (ICharacter &target);
};

#endif
