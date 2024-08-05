#ifndef RPN_HPP
#define RPN_HPP

class RPN
{
  public:
	RPN ();
	RPN (const RPN &copy);
	const RPN &operator= (const RPN &copy);
	~RPN ();

	static int calculate (const char *input);
};

#endif
