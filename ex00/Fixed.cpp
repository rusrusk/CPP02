#include "Fixed.hpp"

Fixed::Fixed() : _fixed_point_nb(0) {

	std::cout << "Default constructor called" << std::endl;
}

// Fixed::Fixed(const int n) : _fixed_point_nb(n) {

// 	std::cout << "Parametric constructor called" << std::endl;
// }

Fixed::~Fixed() {

	std::cout << "Destructor called" << std::endl;
}
 
Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_fixed_point_nb = rhs.getRawBits();
	}
	return *this;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits function gets called" << std::endl;
	this->_fixed_point_nb = raw;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits function gets called" << std::endl;
	return this->_fixed_point_nb;
}
