#include "Fixed.hpp"

Fixed::Fixed ()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point_number = 0;
}

Fixed::Fixed (const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &
Fixed::operator= (const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->fixed_point_number = copy.getRawBits ();
	return (*this);
}

Fixed::~Fixed () { std::cout << "Destructor called" << std::endl; }

int
Fixed::getRawBits (void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fixed_point_number;
}

void
Fixed::setRawBits (int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	fixed_point_number = raw;
}
