#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "I_Character.hpp"
#include "A_Materia.hpp"
#include <string>

#define NULL 0

class Character : public ICharacter
{
    private:
        AMateria *equipped_materia[4];
        std::string character_name;

    public:
        Character();
        Character(const std::string& name);
        Character(const Character& copy);
        Character& operator=(const Character& copy);
        ~Character();

        std::string const &getName () const;
	    void equip (AMateria *m);
	    void unequip (int idx);
	    void use (int idx, ICharacter &target);
};

#endif
