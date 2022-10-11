#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

	public :
			Fixed();
			// Fixed(const int n);
			Fixed(Fixed const &src);
			~Fixed();
			Fixed &operator=(Fixed const &rhs);
			
			int getRawBits(void) const;
			void setRawBits(int const raw);

	private :
			int					_fixed_point_nb;
			static const int	FIXED_POINT_FRACTIONAL_BITS = 8;
};


#endif
