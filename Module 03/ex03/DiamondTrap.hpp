#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
  public:
	DiamondTrap ();
	DiamondTrap (const std::string &robot_name);
	DiamondTrap (const DiamondTrap &copy);
	DiamondTrap &operator= (const DiamondTrap &copy);
	~DiamondTrap ();

	void whoAmI ();

  private:
	std::string name;
};
