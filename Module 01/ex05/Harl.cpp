#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(const std::string level) const
{
	void (Harl::*function[4])() const;
	function[DEBUG] = &Harl::debug;
	function[INFO] = &Harl::info;
	function[WARNING] = &Harl::warning;
	function[ERROR] = &Harl::error;

	std::string levels[4];
	levels[DEBUG] = "DEBUG";
	levels[INFO] = "INFO";
	levels[WARNING] = "WARNING";
	levels[ERROR] = "ERROR";

	for (int i = DEBUG; i <= ERROR; i++)
		if (level == levels[i])
			(this->*function[i])();
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
		   "coming foryears whereas you started working here since last month."
		<< std::endl;
}

void Harl::error() const
{
	std::cout << "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
}
