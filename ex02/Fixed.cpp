#include "Fixed.hpp"

Fixed::Fixed() : _fixed_point_nb(0) {

	std::cout << "Constructor called" << std::endl;
}

Fixed::~Fixed() {

	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const &other) {

	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=( Fixed const &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_fixed_point_nb = other.GetRawBits();
	}
	return *this;
}

void Fixed::SetRawBits(int const raw) {
	this->_fixed_point_nb = raw;
}

int Fixed::GetRawBits(void) const {

	return this->_fixed_point_nb;
}

Fixed::Fixed(const int int_to_fixedpoint) : _fixed_point_nb(int_to_fixedpoint << _nb_of_fract_bits) {

	std::cout << "From int to fixed point conversion" << std::endl;
}

Fixed::Fixed(const float float_to_fixedpoint) : _fixed_point_nb(std::roundf(float_to_fixedpoint * FIXED_POINT_ONE)) {

	std::cout << "From float to fixed point conversion" << std::endl;
}

int Fixed::ToInt(void) const {
	return (_fixed_point_nb >> _nb_of_fract_bits);
}

float Fixed::ToFloat(void) const {
	return ((float)this->_fixed_point_nb / FIXED_POINT_ONE);
}

bool Fixed::operator>(const Fixed &other) {

	return this->_fixed_point_nb > other._fixed_point_nb;
}

bool Fixed::operator<(const Fixed &other) {
	
	return this->_fixed_point_nb < other._fixed_point_nb;
}

bool Fixed::operator>=(const Fixed &other) {

	return this->GetRawBits() >= other.GetRawBits();
}

bool Fixed::operator<=(const Fixed &other) {

	return this->GetRawBits() <= other.GetRawBits();
}

bool Fixed::operator==(const Fixed &other) {

	return this->GetRawBits() == other.GetRawBits();
}

bool Fixed::operator!=(const Fixed &other) {

	return !(*this == other);
}

const Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(this->ToFloat() + other.ToFloat());
}

const Fixed Fixed::operator-(const Fixed &other) {
	return Fixed(this->ToFloat() - other.ToFloat());
}

const Fixed Fixed::operator*(const Fixed &other) {
	return Fixed(this->ToFloat() * other.ToFloat());
}

const Fixed Fixed::operator/(const Fixed &other) {
	if (other.ToInt() == 0)
		std::cout << "The given value is not divisible!" << std::endl;
	return Fixed(this->ToFloat() / other.ToFloat());
}

Fixed Fixed::operator++(int) {
	Fixed tmp = (*this);
	++_fixed_point_nb;
	return tmp;
}

Fixed Fixed::operator--(int) {
	Fixed tmp = _fixed_point_nb;
	--_fixed_point_nb;
	return tmp;
}


Fixed &Fixed::operator++() {
	this->_fixed_point_nb++;
	return *this;
}

Fixed &Fixed::operator--() {
	this->_fixed_point_nb--;
	return *this;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a._fixed_point_nb < b._fixed_point_nb) 
		return a;
	else
		return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a._fixed_point_nb < b._fixed_point_nb) 
		return a;
	else
		return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a._fixed_point_nb > b._fixed_point_nb)
		return a;
	else
		return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a._fixed_point_nb > b._fixed_point_nb)
		return a;
	else
		return b;
}

std::ostream &operator<<(std::ostream &o, Fixed const &nb) {

	o << nb.ToFloat();
	return o;
}

