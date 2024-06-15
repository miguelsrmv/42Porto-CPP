#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
  public:
	Fixed ();
	Fixed (const Fixed &copy);
	Fixed (const int int_parameter);
	Fixed (const float float_parameter);
	Fixed &operator= (const Fixed &copy);
	~Fixed ();

	// Comparison operators
	bool operator> (const Fixed &copy);
	bool operator<(const Fixed &copy);
	bool operator>= (const Fixed &copy);
	bool operator<= (const Fixed &copy);
	bool operator== (const Fixed &copy);
	bool operator!= (const Fixed &copy);

	// Arithmetic operators
	float operator+ (const Fixed &copy);
	float operator- (const Fixed &copy);
	float operator* (const Fixed &copy);
	float operator/ (const Fixed &copy);

	// Increment/Decrement operators
	Fixed &operator++ ();
	Fixed operator++ (int);
	Fixed &operator-- ();
	Fixed operator-- (int);

	// Max/min functions
	static Fixed &min (Fixed &copy1, Fixed &copy2);
	static const Fixed &min (Fixed const &copy1, Fixed const &copy2);
	static Fixed &max (Fixed &copy1, Fixed &copy2);
	static const Fixed &max (Fixed const &copy1, Fixed const &copy2);

	// Rest of the class
	int getRawBits (void) const;
	void setRawBits (int const raw);
	float toFloat (void) const;
	int toInt (void) const;

  private:
	int fixed_point_number;
	static const int fractional_bits = 8;
};

std::ostream &operator<< (std::ostream &out, const Fixed &copy);

#endif
