#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed &copy);
	Fixed(const int int_parameter);
	Fixed(const float float_parameter);

	Fixed &operator=(const Fixed &copy);
	bool operator>(const Fixed &copy);
	bool operator<(const Fixed &copy);
	bool operator>=(const Fixed &copy);
	bool operator<=(const Fixed &copy);
	bool operator==(const Fixed &copy);
	bool operator!=(const Fixed &copy);

	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

private:
	int fixed_point_number;
	static const int fractional_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &copy);

#endif