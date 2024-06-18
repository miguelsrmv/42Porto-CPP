#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string &level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int level_index = DEBUG;
	while (level_index <= ERROR && levels[level_index] != level)
		level_index++;

	switch (level_index)
	{
	default:
		std::cout << "[ Probably complaining about insignificant problems ] " << std::endl;
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

void Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl
			  << "I love having extra bacon for my "
				 "7XL-double-cheese-triple-pickle-special-ketchup burger. I "
				 "really do!"
			  << std::endl;
}

void Harl::info()
{
	std::cout << "[INFO]" << std::endl
			  << "I cannot believe adding extra bacon costs more money. You "
				 "didn’t putenough bacon in my burger! If you did, I wouldn’t "
				 "be asking for more!"
			  << std::endl;
}

void Harl::warning()
{
	std::cout
		<< "[WARNING]" << std::endl
		<< "I think I deserve to have some extra bacon for free. I’ve been "
		   "coming for years whereas you started working here since last "
		   "month."
		<< std::endl;
}

void Harl::error()
{
	std::cout << "[ERROR]" << std::endl
			  << "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
}
