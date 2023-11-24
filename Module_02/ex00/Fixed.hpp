/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:22:16 by tzanchi           #+#    #+#             */
/*   Updated: 2023/11/24 16:16:58 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed
{
private:
	int					_rawBits;
	static const int	_fractionalBits = 8;

public:
	Fixed( void );
	Fixed( const Fixed& src );
	Fixed& operator=( const Fixed& src) ;
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};
