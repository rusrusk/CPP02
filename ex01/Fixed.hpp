#ifndef FIXED_HPP
# define FIXED_HPP
# define FIXED_POINT_ONE (1 << 8)
# include <iostream>
# include <cmath>


class Fixed {

	public :
			Fixed ();
			Fixed (const int int_to_fixedpoint);
			Fixed (const float float_to_fixedpoint);
			Fixed (const Fixed &src);
			Fixed &operator=(const Fixed &rhs);
			~Fixed();

			int getRawBits(void) const;
			void setRawBits(int const raw);
			float	toFloat(void) const; //converts the fixed point value to floating-point value
			int		toInt(void) const; //converts the fixed_point value to integer value 

	private :
			int					_fixed_point_nb;
			static const int	_nb_of_fract_bits = 8;
};

			std::ostream &operator<<(std::ostream &o, Fixed const &nb);

#endif
