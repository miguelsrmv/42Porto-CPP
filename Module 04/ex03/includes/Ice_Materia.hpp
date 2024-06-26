#ifndef ICE_MATERIA_HPP
#define ICE_MATERIA_HPP

#include "A_Materia.hpp"

class Ice_Materia : public AMateria
{
  public:
	Ice_Materia ();
	Ice_Materia (const Ice_Materia& copy);
	Ice_Materia &operator=(const Ice_Materia& copy);
	~Ice_Materia ();

	Ice_Materia *clone () const;
	void use (ICharacter &target);
};


#endif
