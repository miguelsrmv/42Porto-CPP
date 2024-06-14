#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

enum error_code
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

class Harl
{
  public:
	Harl ();
	~Harl ();
	void complain (std::string &level);

  private:
	void debug ();
	void info ();
	void warning ();
	void error ();
};

#endif
