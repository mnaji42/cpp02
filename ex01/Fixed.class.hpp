/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 22:36:11 by mnaji             #+#    #+#             */
/*   Updated: 2020/02/21 22:10:06 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>
# include <cmath>
# include <ostream>

class	Fixed
{
	private:
		int _val;
		static const int _bit;
		static const int _power;
		
	public:
		Fixed();
		Fixed(const int val);
        Fixed(const float val);
		Fixed(const Fixed &f);
		~Fixed();
		Fixed &operator=(const Fixed &f);
		int getRawBits() const;
        void setRawBits(const int raw);
		float toFloat() const;
        int toInt() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &c);

#endif
