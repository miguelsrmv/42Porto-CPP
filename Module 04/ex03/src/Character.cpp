#include "Character.hpp"

Character::Character () : character_name ("No name")
{
	// std::cout << "Character default constructor called" << std::endl ;

	for (int idx = 0; idx < 4; idx++)
		equipped_materia[idx] = NULL;
}

Character::Character (const std::string &name) : character_name (name)
{
	// std::cout << "Character parametrized constructor called" << std::endl ;

	for (int idx = 0; idx < 4; idx++)
		equipped_materia[idx] = NULL;
}

Character::Character (const Character &copy)
{
	// std::cout << "Character copy constructor called" << std::endl ;

	*this = copy;
}

Character &
Character::operator= (const Character &copy)
{
	// std::cout << "Character = operator called" << std::endl ;

	if (this != &copy)
		{
			this->character_name = copy.character_name;
			for (int i = 0; i < 4; i++)
				{
					if (this->equipped_materia[i])
						delete (this->equipped_materia[i]);
					if (copy.equipped_materia[i])
						this->equipped_materia[i]
							= (copy.equipped_materia[i])->clone ();
					else
						this->equipped_materia[i] = NULL;
				}
		}
	return (*this);
}

Character::~Character ()
{
	// std::cout << "Character destructor called" << std::endl ;
}

std::string const &
Character::getName () const
{
	return this->character_name;
}

void
Character::equip (AMateria *m)
{
	int idx = 0;

	while (idx < 4 && this->equipped_materia[idx])
		idx++;

	if (idx == 4)
		{
			std::cout << "Couldn't equip Materia: slots are full!"
					  << std::endl;
			return;
		}

	this->equipped_materia[idx] = m;
}

void
Character::unequip (int idx)
{
	if (idx < 0 || idx > 3)
		{
			std::cout << "Couldn't unequip Materia: invalid index!"
					  << std::endl;
			return;
		}
    
	this->equipped_materia[idx] = NULL;
}

void
Character::use (int idx, ICharacter &target)
{
	if (this->equipped_materia[idx] == NULL)
		{
			std::cout << "Couldn't use Materia: slot is empty!" << std::endl;
			return;
		}

	this->equipped_materia[idx]->use (target);
}
