#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

typedef enum types
{
	CHAR_TYPE,
	INT_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE,
	PSEUDO_LITERAL_TYPE,
	INVALID_TYPE
} types;

class ScalarConverter
{
  public:
	static void convert (std::string &parameter);

  private:
	// Private Constructors becuase class must not be instanciable by users
	ScalarConverter ();
	ScalarConverter (const ScalarConverter &copy);
	const ScalarConverter &operator= (const ScalarConverter &copy);
	~ScalarConverter ();

	// Gets type that was inputed
	static types get_type (const std::string &parameter);
	static bool is_char (const std::string &parameter);
	static bool is_int (const std::string &parameter);
	static bool is_float (const std::string &parameter);
	static bool is_double (const std::string &parameter);
	static bool is_pseudo_literal (const std::string &parameter);

	// Converts type
	static void convert_data (const std::string &parameter,
							  long double number);
	static void convert_char (char c, const std::string &parameter);
	static void convert_int (int integer, const std::string &parameter);
	static void convert_float (float floating_point,
							   const std::string &parameter);
	static void convert_double (double doubling_point,
								const std::string &parameter);

	// Print pseudoliterals
	static void print_pseudoliterals (const std::string &parameter);

	// Print invalid input message
	static void print_invalid_input (const std::string &parameter);

	// Overflow checker
	static bool overflow_check (const std::string &parameter,
								types parameter_type);
};

#endif
