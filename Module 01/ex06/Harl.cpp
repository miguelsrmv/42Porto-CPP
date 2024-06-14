#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(const std::string &level) const
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int index = -1;

	for (int i = DEBUG; i <= ERROR; i++)
		if (levels[i] == level)
		{
			index = i;
			break;
		}

	switch (index)
	{
	default:
		break;
	case DEBUG:
		Harl::debug();
		// fall through
	case INFO:
		Harl::info();
		// fall through
	case WARNING:
		Harl::warning();
		// fall through
	case ERROR:
		Harl::error();
	};
}

void Harl::debug(void) const
{
	std::cout << "I love having extra bacon for my "
				 "7XL-double-cheese-triple-pickle-special-ketchup burger. I "
				 "really do!"
			  << std::endl;
}

void Harl::info() const
{
	std::cout << "I cannot believe adding extra bacon costs more money. You "
				 "didn’t putenough bacon in my burger! If you did, I wouldn’t "
				 "be asking for more!"
			  << std::endl;
}

void Harl::warning() const
{
	std::cout
		<< "I think I deserve to have some extra bacon for free. I’ve been "
		   "coming for years whereas you started working here since last "
		   "month."
		<< std::endl;
}

void Harl::error() const
{
	std::cout << "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
}
