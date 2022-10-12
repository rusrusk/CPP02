#ifndef FIXED_HPP
# define FIXED_HPP
# define FIXED_POINT_ONE (1 << 8)
# include <iostream>
# include <cmath>



class Fixed {

	public :
			Fixed();
			Fixed( Fixed const &other);
			Fixed &operator=( Fixed const &other);
			Fixed(const int int_to_fixedpoint);
			Fixed(const float float_to_fixedpoint);
			~Fixed();

			void SetRawBits(int const raw);
			int GetRawBits(void) const;
			int ToInt(void) const;
			float ToFloat(void) const;

			//Comparison operators
			bool operator>(const Fixed &other);
			bool operator>=(const Fixed &other);
			bool operator<(const Fixed &other);
			bool operator<=(const Fixed &other);
			bool operator==(const Fixed &other);
			bool operator!=(const Fixed &other);

			//Arithmetic operators
			const Fixed operator+(const Fixed &other) const;
			const Fixed operator-(const Fixed &other);
			const Fixed operator*(const Fixed &other);
			const Fixed operator/(const Fixed &other);

			//Increment/Decrement operators
			Fixed &operator++();
			Fixed operator++(int);
			Fixed operator--(int);
			Fixed &operator--();

			static Fixed		&min(Fixed &a, Fixed &b);
			static const Fixed	&min(const Fixed &a, const Fixed &b);

			static Fixed		&max(Fixed &a, Fixed &b);
			static const Fixed	&max(const Fixed &a, const Fixed &b);

	private :
			int					_fixed_point_nb;
			static const int	_nb_of_fract_bits = 8;
};

			// static Fixed tmp;
			std::ostream &operator<<(std::ostream &o, Fixed const &nb);


#endif
