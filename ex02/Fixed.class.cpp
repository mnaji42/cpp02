/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaji <mnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 22:35:52 by mnaji             #+#    #+#             */
/*   Updated: 2020/02/22 00:00:11 by mnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

const int Fixed::_bit = 8;
const int Fixed::_power = 256;

Fixed::Fixed()
{
	_val = 0;
}

Fixed::Fixed(const int intValue)
{
	_val = intValue * _power;
}

Fixed::Fixed(const float floatValue)
{
	_val = roundf(floatValue * _power);
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &f)
{
	_val = f._val;
	*this = f;
}

int Fixed::getRawBits() const
{
    return (_val);
}

void Fixed::setRawBits(const int val)
{
    _val = val;
}

float Fixed::toFloat() const
{
    return (float(_val) / _power);
}

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
    return (out << f.toFloat());
}

int Fixed::toInt() const
{
    return (_val / _power);
}


Fixed &Fixed::operator=(const Fixed &f)
{
	if (this != &f)
    	_val = f.getRawBits();
    return (*this);
}

bool Fixed::operator>(const Fixed &f) const
{
	if (_val > f._val)
		return (1);
	return (0);
}

bool Fixed::operator<(const Fixed &f) const
{
    if (_val < f._val)
		return (1);
	return (0);
}

bool Fixed::operator>=(const Fixed &f) const
{
    if (_val >= f._val)
		return (1);
	return (0);
}

bool Fixed::operator<=(const Fixed &f) const
{
    if (_val <= f._val)
		return (1);
	return (0);
}

bool Fixed::operator==(const Fixed &f) const
{
    if (_val == f._val)
		return (1);
	return (0);
}

bool Fixed::operator!=(const Fixed &f) const
{
    if (_val != f._val)
		return (1);
	return (0);
}

Fixed Fixed::operator+(const Fixed &f) const
{
    return _val + f._val;
}

Fixed Fixed::operator-(const Fixed &f) const
{
    return _val - f._val;
}

Fixed Fixed::operator*(const Fixed &f) const
{
    return Fixed(toFloat() * f.toFloat());
}

Fixed Fixed::operator/(const Fixed &f) const
{
    return Fixed(toFloat() / f.toFloat());
}

Fixed &Fixed::operator++()
{
    _val++;
    return *this;
}

Fixed &Fixed::operator--()
{
    _val--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed f = *this;
    _val++;
    return f;
}

Fixed Fixed::operator--(int)
{
    Fixed f = *this;
    _val--;
    return f;
}

const Fixed &Fixed::min(const Fixed &f, const Fixed &f2)
{
	if (f._val >= f2._val)
		return (f2);
	return (f);
}

Fixed &Fixed::min(Fixed &f, Fixed &f2)
{
	if (f._val >= f2._val)
		return (f2);
	return (f);
}

const Fixed &Fixed::max(const Fixed &f, const Fixed &f2)
{
	if (f._val >= f2._val)
		return (f);
	return (f2);
}

Fixed &Fixed::max(Fixed &f, Fixed &f2)
{
    if (f._val >= f2._val)
		return (f);
	return (f2);
}
