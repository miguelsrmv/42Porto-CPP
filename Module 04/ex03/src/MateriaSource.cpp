#include "MateriaSource.hpp"

MateriaSource::MateriaSource ()
{
	for (int idx = 0; idx < 4; idx++)
		_learnt_materias[idx] = NULL;
	// std::cout << "MateriaSource default constructor called" << std::endl ;
}

MateriaSource::MateriaSource (const MateriaSource &copy)
{
	// std::cout << "MateriaSource copy constructor called" << std::endl ;

	*this = copy;
}

MateriaSource &
MateriaSource::operator= (const MateriaSource &copy)
{
	if (this != &copy)
		{
			for (int idx = 0; idx < 4; idx++)
				{
					if (this->_learnt_materias[idx])
						delete (this->_learnt_materias[idx]);
					if (copy._learnt_materias[idx])
						this->_learnt_materias[idx]
							= (copy._learnt_materias[idx])->clone ();
					else
						this->_learnt_materias[idx] = NULL;
				}
		}
	return (*this);
}

MateriaSource::~MateriaSource ()
{
	// std::cout << "MateriaSource default destructor called" << std::endl ;

	for (int idx = 0; idx < 4; idx++)
		{
			if (_learnt_materias[idx])
				delete (_learnt_materias[idx]);
		}
}

void
MateriaSource::learnMateria (AMateria *materia)
{
	int idx = 0;

	while (idx < 4 && this->_learnt_materias[idx])
		idx++;

	if (idx == 4)
		{
			std::cout << "Couldn't learn Materia: slots are full!"
					  << std::endl;
			return;
		}

	this->_learnt_materias[idx] = materia;
}

AMateria *
MateriaSource::createMateria (std::string const &type)
{
	int idx = 0;

	while (idx < 4 && this->_learnt_materias[idx]
		   && this->_learnt_materias[idx]->getType () != type)
		idx++;

	if (idx == 4)
		{
			std::cout << "Couldn't create Materia: this materia type has not "
						 "been learned before!"
					  << std::endl;
			return NULL;
		}

	return (this->_learnt_materias[idx]->clone ());
}
