#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(const std::string &robot_name);
    FragTrap(const FragTrap &copy);
    FragTrap &operator=(const FragTrap &copy);
    ~FragTrap();

    void highFivesGuys(void);
};
