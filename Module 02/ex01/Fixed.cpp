#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point_number = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int int_parameter)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point_number = int_parameter * (1 << this->fractional_bits);
}

Fixed::Fixed(const float float_parameter)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point_number = roundf(float_parameter * (1 << this->fractional_bits));
}

Fixed &
Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->fixed_point_number = copy.getRawBits();
	return (*this);
}

std::ostream &
operator<<(std::ostream &out, const Fixed &copy)
{
	out << copy.toFloat();
	return (out);
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const
{
	return fixed_point_number;
}

void Fixed::setRawBits(int const raw)
{
	fixed_point_number = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)(this->fixed_point_number) / (float)(1 << this->fractional_bits));
}

int Fixed::toInt(void) const
{
	return (this->fixed_point_number >> this->fractional_bits);
}
