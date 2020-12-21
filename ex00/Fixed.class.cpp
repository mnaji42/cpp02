/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 22:35:52 by mnaji             #+#    #+#             */
/*   Updated: 2020/02/21 02:55:45 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

const int Fixed::_bit = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_val = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	_val = f._val;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
    return _val;
}

void Fixed::setRawBits(const int val)
{
	std::cout << "setRawBits member function called" << std::endl;
    _val = val;
}

Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &f)
    	_val = f.getRawBits();
    return *this;
}
