/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:22:18 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/05 17:39:43 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/* Constructors and destructor *********************************************** */

Fixed::Fixed() : _rawBits( 0 ) {}

Fixed::Fixed( const int n ) : _rawBits( n << _fractionalBits ) {}

Fixed::Fixed( const float n ) : _rawBits( roundf(n * (1 << _fractionalBits)) ) {}

Fixed::Fixed( const Fixed& src ) : _rawBits( src._rawBits ) {}

Fixed::~Fixed() {}

/* Operators overload ******************************************************** */
/* Assignment operator */
Fixed&	Fixed::operator=( const Fixed& src )
{
	if (this != &src)
		_rawBits = src.getRawBits();
	return (*this);
}

/* Artihmetic operators */
Fixed	Fixed::operator+( const Fixed& src ) const{
	return (Fixed( this->toFloat() + src.toFloat() ));}

Fixed	Fixed::operator-( const Fixed& src ) const {
	return (Fixed( this->toFloat() - src.toFloat() ));}

Fixed	Fixed::operator*( const Fixed& src ) const {
	return (Fixed( this->toFloat() * src.toFloat() ));}

Fixed	Fixed::operator/( const Fixed& src ) const {
	return (Fixed( this->toFloat() / src.toFloat() ));}

/* Comparison operators */
bool	Fixed::operator<( const Fixed& src ) const {
	return (this->getRawBits() < src.getRawBits());}

bool	Fixed::operator>( const Fixed& src ) const {
	return (this->getRawBits() > src.getRawBits());}

bool	Fixed::operator<=( const Fixed& src ) const {
	return (this->getRawBits() <= src.getRawBits());}

bool	Fixed::operator>=( const Fixed& src ) const {
	return (this->getRawBits() >= src.getRawBits());}

bool	Fixed::operator==( const Fixed& src ) const {
	return (this->getRawBits() == src.getRawBits());}

bool	Fixed::operator!=( const Fixed& src ) const {
	return (this->getRawBits() != src.getRawBits());}

/* Increment operators */
Fixed&	Fixed::operator--()
{
	_rawBits--;
	return (*this);
}

Fixed&	Fixed::operator++()
{
	_rawBits++;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;

	_rawBits--;
	return ( temp );
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;

	_rawBits++;
	return ( temp );
}

/* Min and max *************************************************************** */
Fixed&	Fixed::min( Fixed& a, Fixed& b)
{
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::min( const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	else
		return (b);
}

Fixed&	Fixed::max( Fixed& a, Fixed& b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::max( const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	else
		return (b);
}

/* Member functions ********************************************************** */

int	Fixed::getRawBits( void ) const { return (_rawBits); }

void	Fixed::setRawBits( int const raw ) { _rawBits = raw; }

float	Fixed::toFloat( void ) const {
	return ((float)_rawBits / (1 << _fractionalBits));}

int	Fixed::toInt( void ) const {
	return (_rawBits >> _fractionalBits);}

/* Display operator overload ************************************************* */

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
