/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:34:35 by tzanchi           #+#    #+#             */
/*   Updated: 2023/11/28 19:46:55 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

class Point
{
private:
	const Fixed	_x;
	const Fixed	_y;

public:
	Point( void );
	Point( const float x, const float y );
	Point( const Point& src );
	Point&	operator=( const Point& src );
	~Point();

	Fixed	getX( void ) const;
	Fixed	getY( void ) const;
};
