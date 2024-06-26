#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
  public:
	Brain ();
	Brain (const Brain &copy);
	Brain &operator= (const Brain &copy);
	~Brain ();

  private:
	std::string *ideas;
};

#endif
