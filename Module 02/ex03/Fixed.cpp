#include "Fixed.hpp"

Fixed::Fixed ()
{
	// std::cout << "Default constructor called" << std::endl;
	this->fixed_point_number = 0;
}

Fixed::Fixed (const Fixed &copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed (const int int_parameter)
{
	// std::cout << "Int constructor called" << std::endl;
	this->fixed_point_number = int_parameter * (1 << this->fractional_bits);
}

Fixed::Fixed (const float float_parameter)
{
	// std::cout << "Float constructor called" << std::endl;
	this->fixed_point_number = float_parameter * (1 << this->fractional_bits);
}

Fixed &
Fixed::operator= (const Fixed &copy)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->fixed_point_number = copy.getRawBits ();
	return (*this);
}

Fixed::~Fixed ()
{
	// std::cout << "Destructor called" << std::endl;
}

std::ostream &
operator<< (std::ostream &out, const Fixed &copy)
{
	out << copy.toFloat ();
	return (out);
}

bool
Fixed::operator> (const Fixed &copy)
{
	return (this->getRawBits () > copy.getRawBits ());
}

bool
Fixed::operator<(const Fixed &copy)
{
	return (this->getRawBits () < copy.getRawBits ());
}

bool
Fixed::operator>= (const Fixed &copy)
{
	return (this->getRawBits () >= copy.getRawBits ());
}

bool
Fixed::operator<= (const Fixed &copy)
{
	return (this->getRawBits () <= copy.getRawBits ());
}

bool
Fixed::operator== (const Fixed &copy)
{
	return (this->getRawBits () == copy.getRawBits ());
}

bool
Fixed::operator!= (const Fixed &copy)
{
	return (this->getRawBits () != copy.getRawBits ());
}

float
Fixed::operator+ (const Fixed &copy)
{
	return (this->toFloat () + copy.toFloat ());
}

float
Fixed::operator- (const Fixed &copy)
{
	return (this->toFloat () - copy.toFloat ());
}

float
Fixed::operator* (const Fixed &copy)
{
	return (this->toFloat () * copy.toFloat ());
}

float
Fixed::operator/ (const Fixed &copy)
{
	return (this->toFloat () / copy.toFloat ());
}

Fixed &
Fixed::operator++ ()
{
	fixed_point_number++;
	return (*this);
}

Fixed
Fixed::operator++ (int)
{
	Fixed this_copy (*this);
	fixed_point_number++;
	return (this_copy);
}

Fixed &
Fixed::operator-- ()
{
	fixed_point_number--;
	return (*this);
}

Fixed
Fixed::operator-- (int)
{
	Fixed this_copy (*this);
	fixed_point_number--;
	return (this_copy);
}

Fixed &
Fixed::min (Fixed &copy1, Fixed &copy2)
{
	if (copy1.getRawBits () < copy2.getRawBits ())
		return (copy1);
	return (copy2);
}

const Fixed &
Fixed::min (Fixed const &copy1, Fixed const &copy2)
{
	if (copy1.getRawBits () < copy2.getRawBits ())
		return (copy1);
	return (copy2);
}

Fixed &
Fixed::max (Fixed &copy1, Fixed &copy2)
{
	if (copy1.getRawBits () > copy2.getRawBits ())
		return (copy1);
	return (copy2);
}

const Fixed &
Fixed::max (Fixed const &copy1, Fixed const &copy2)
{
	if (copy1.getRawBits () > copy2.getRawBits ())
		return (copy1);
	return (copy2);
}

int
Fixed::getRawBits (void) const
{
	return fixed_point_number;
}

void
Fixed::setRawBits (int const raw)
{
	fixed_point_number = raw;
}

float
Fixed::toFloat (void) const
{
	return ((float)(this->fixed_point_number)
			/ (float)(1 << this->fractional_bits));
}

int
Fixed::toInt (void) const
{
	return (this->fixed_point_number / (1 << this->fractional_bits));
}
