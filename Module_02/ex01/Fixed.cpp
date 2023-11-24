/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:22:18 by tzanchi           #+#    #+#             */
/*   Updated: 2023/11/24 20:47:35 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _rawBits( 0 )
{
	std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief Construct a new Fixed object from an int. We shift the value by 
 * _fractionalBits parts to access the int part
 * 
 * @param n The integer to convert
 */
Fixed::Fixed( const int n ) : _rawBits( n << _fractionalBits )
{
	std::cout << "Int constructor called" << std::endl;
}

/**
 * @brief Construct a new Fixed object from a float. The value is multiplied by
 * (1 << _fractionalBits) which is equivalent to multiply by (2 ^ _fractionalBits)
 * and allows to calculates the fixed-point representation of the float. roundf()
 * is then used to store the result in an int
 * 
 * @param n The float to convert
 */
Fixed::Fixed( const float n ) : _rawBits( roundf(n * (1 << _fractionalBits)) )
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed& Fixed::operator=( const Fixed& src )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_rawBits = src._rawBits;
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/* ************************************************************************** */

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void	Fixed::setRawBits( int const raw )
{
	this->_rawBits = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)_rawBits / (1 << _fractionalBits));
}

int	Fixed::toInt( void ) const
{
	return (_rawBits >> _fractionalBits);
}

/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	float	value = fixed.toFloat();
	os << value;
	return os;
}
