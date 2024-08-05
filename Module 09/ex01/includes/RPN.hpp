#ifndef RPN_HPP
#define RPN_HPP

#include <stack>

class RPN
{
  public:
	RPN ();
	RPN (const RPN &copy);
	const RPN &operator= (const RPN &copy);
	~RPN ();

	static int calculate (const char *input);

  private:
	static bool is_number (const char substring);
	static bool is_operator (const char substring);
	static void perform_operation (std::stack<int> &stack, char buffer);
	static int error_log ();
};

#endif
