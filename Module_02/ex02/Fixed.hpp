/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:22:16 by tzanchi           #+#    #+#             */
/*   Updated: 2023/11/28 18:38:28 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <limits.h>

class Fixed
{
private:
	int					_rawBits;
	static const int	_fractionalBits = 8;
	static const int	FIXED_NAN = INT_MAX;
	static const int	FIXED_POS_INF = INT_MAX - 1;
	static const int	FIXED_NEG_INF = INT_MIN;

public:
	Fixed( void );
	Fixed( const int n );
	Fixed( const float n );
	Fixed( const Fixed& src );
	~Fixed();

	Fixed&	operator=( const Fixed& src );

	Fixed	operator+( const Fixed& src ) const;
	Fixed	operator-( const Fixed& src ) const;
	Fixed	operator*( const Fixed& src ) const;
	Fixed	operator/( const Fixed& src ) const;

	bool	operator<( const Fixed& src ) const;
	bool	operator>( const Fixed& src ) const;
	bool	operator<=( const Fixed& src ) const;
	bool	operator>=( const Fixed& src ) const;
	bool	operator==( const Fixed& src ) const;
	bool	operator!=( const Fixed& src ) const;

	Fixed&	operator--();
	Fixed&	operator++();
	Fixed	operator--(int);
	Fixed	operator++(int);

	static Fixed&	min( Fixed& a, Fixed& b );
	static const Fixed&	min( const Fixed& a, const Fixed& b );
	static Fixed&	max( Fixed& a, Fixed& b );
	static const Fixed&	max( const Fixed& a, const Fixed& b );


	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	friend std::ostream&	operator<<( std::ostream& os, const Fixed& fixed );
};
