#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "A_Materia.hpp"
#include "I_Character.hpp"
#include <string>

class Character : public ICharacter
{
  private:
	AMateria *_equipped_materia[4];
	std::string _character_name;

  public:
	Character ();
	Character (const std::string &name);
	Character (const Character &copy);
	Character &operator= (const Character &copy);
	~Character ();

	std::string const &getName () const;
	void equip (AMateria *m);
	void unequip (int idx);
	void use (int idx, ICharacter &target);
};

#endif
