#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
  public:
	ScavTrap ();
	ScavTrap (const std::string &robot_name);
	ScavTrap (const ScavTrap &copy);
	ScavTrap &operator= (const ScavTrap &copy);
	~ScavTrap ();

	void guardGate ();
	void attack (const std::string &target);
};
