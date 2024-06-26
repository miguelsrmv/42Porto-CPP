#ifndef MATERIA_SOURCE
#define MATERIA_SOURCE

#include "A_Materia.hpp"
#include "I_MateriaSource.hpp"

class MateriaSource : public IMateriaSource

{
  public:
	MateriaSource ();
	MateriaSource (const MateriaSource &copy);
	MateriaSource &operator= (const MateriaSource &copy);
	~MateriaSource ();

	void learnMateria (AMateria *materia);
	AMateria *createMateria (std::string const &type);

  private:
	AMateria *_learnt_materias[4];
};

#endif
