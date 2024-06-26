#include "Character.hpp"

Character::Character () : _character_name ("No name")
{
	// std::cout << "Character default constructor called" << std::endl ;

	for (int idx = 0; idx < 4; idx++)
		_equipped_materia[idx] = NULL;
}

Character::Character (const std::string &name) : _character_name (name)
{
	// std::cout << "Character parametrized constructor called" << std::endl ;

	for (int idx = 0; idx < 4; idx++)
		_equipped_materia[idx] = NULL;
}

Character::Character (const Character &copy)
{
	// std::cout << "Character copy constructor called" << std::endl ;

	for (int idx = 0; idx < 4; idx++)
		_equipped_materia[idx] = NULL;

	*this = copy;
}

Character &
Character::operator= (const Character &copy)
{
	// std::cout << "Character = operator called" << std::endl ;

	if (this != &copy)
		{
			this->_character_name = copy._character_name;
			for (int idx = 0; idx < 4; idx++)
				{
					if (this->_equipped_materia[idx])
						delete (this->_equipped_materia[idx]);
					if (copy._equipped_materia[idx])
						this->_equipped_materia[idx]
							= (copy._equipped_materia[idx])->clone ();
					else
						this->_equipped_materia[idx] = NULL;
				}
		}
	return (*this);
}

Character::~Character ()
{
	// std::cout << "Character destructor called" << std::endl ;

	for (int idx = 0; idx < 4; idx++)
		{
			if (_equipped_materia[idx])
				delete (_equipped_materia[idx]);
		}
}

std::string const &
Character::getName () const
{
	return this->_character_name;
}

void
Character::equip (AMateria *m)
{
	int idx = 0;

	while (idx < 4 && this->_equipped_materia[idx])
		idx++;

	if (idx == 4)
		{
			std::cout << "Couldn't equip Materia : slots are full!"
					  << std::endl;
			return;
		}

	this->_equipped_materia[idx] = m;
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

	if (this->_equipped_materia[idx] == NULL)
		{
			std::cout << "Couldn't unequip Materia: no materia exists on this slot!"
					  << std::endl;
			return;
		}
	this->_equipped_materia[idx] = NULL;
}

void
Character::use (int idx, ICharacter &target)
{
	if (this->_equipped_materia[idx] == NULL)
		{
			std::cout << "Couldn't use Materia: slot is empty!" << std::endl;
			return;
		}

	this->_equipped_materia[idx]->use (target);
}
