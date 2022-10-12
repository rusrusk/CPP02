#include "Fixed.hpp"

Fixed::Fixed() : _fixed_point_nb(0) {

	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {

	std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw) {
	this->_fixed_point_nb = raw;
}

int Fixed::getRawBits(void) const {
	return this->_fixed_point_nb;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_fixed_point_nb = rhs.getRawBits();
	}
	return *this;
}

Fixed::Fixed(const int int_to_fixedpoint) : _fixed_point_nb(int_to_fixedpoint << _nb_of_fract_bits) {

	std::cout << "Int constructor called" << std::endl;

}

Fixed::Fixed(const float float_to_fixedpoint) : _fixed_point_nb((std::roundf)(float_to_fixedpoint * FIXED_POINT_ONE))  {

	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const {
	return ((float)this->_fixed_point_nb / FIXED_POINT_ONE);
}

int Fixed::toInt(void) const {

	return (this->_fixed_point_nb >> _nb_of_fract_bits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs) {

	o << rhs.toFloat();
	return o;
}
