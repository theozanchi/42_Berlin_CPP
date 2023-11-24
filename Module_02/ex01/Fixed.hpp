/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:22:16 by tzanchi           #+#    #+#             */
/*   Updated: 2023/11/24 20:44:37 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed
{
private:
	int					_rawBits;
	static const int	_fractionalBits = 8;

public:
	Fixed( void );
	Fixed( const int n );
	Fixed( const float n );
	Fixed( const Fixed& src );
	Fixed& operator=( const Fixed& src) ;
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	friend std::ostream&	operator<<( std::ostream& os, const Fixed& fixed );
};
