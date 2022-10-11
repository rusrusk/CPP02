#ifndef FIXED_HPP
# define FIXED_HPP
# define FIXED_POINT_ONE (1 << 8)
# include <iostream>
# include <cmath>



class Fixed {

	public :
			Fixed();
			Fixed(const Fixed &src);
			Fixed &operator=(const Fixed &rhs);
			Fixed(const int int_to_fixedpoint);
			Fixed(const float float_to_fixedpoint);
			~Fixed();

			void SetRawBits(int const raw);
			int GetRawBits(void) const;
			int ToInt(void) const;
			int ToFloat(void) const;

			//Comparison operators
			bool operator>(const Fixed &src);
			bool operator>=(const Fixed &src);
			bool operator<=(const Fixed &src);
			bool operator==(const Fixed &src);
			bool operator!=(const Fixed &src);

			//Arithmetic operators
			Fixed operator+(const Fixed &src);
			Fixed operator-(const Fixed &src);
			Fixed operator*(const Fixed &src);
			Fixed operator/(const Fixed &src);

			//Increment/Decrement operators
			Fixed &operator++(int nb);
			Fixed &operator--(int nb);
			Fixed &operator+ (Fixed);
			Fixed &operator- (Fixed);

			static int			min(int &a, int &b);
			static const int	&min(const int &a, const int &b);
			// {
			// 	if (a > b)
			// 		return a;
			// 	else
			// 		return b;
			// };

			static int			max(int &a, int &b);
			static const int	&max(const int &a, const int &b);

	private :
			int					_fixed_point_nb;
			static const int	_nb_of_fract_bits = 8;
};


			std::ostream &operator<<(std::ostream &o, Fixed const &nb);


#endif