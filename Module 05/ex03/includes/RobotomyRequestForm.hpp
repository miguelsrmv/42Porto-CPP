#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
  public:
	// Constructors and Destructors
	RobotomyRequestForm (const std::string &target);
	RobotomyRequestForm (const RobotomyRequestForm &copy);
	~RobotomyRequestForm ();

	// Execute function
	void execute (void) const;

  private:
	std::string _target;

	RobotomyRequestForm &operator= (const RobotomyRequestForm &copy);
};

#endif
