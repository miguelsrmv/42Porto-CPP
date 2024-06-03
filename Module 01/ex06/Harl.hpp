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
	void complain (const std::string &level) const;

  private:
	void debug () const;
	void info () const;
	void warning () const;
	void error () const;
};

#endif