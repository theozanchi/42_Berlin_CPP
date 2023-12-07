/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:34:37 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/06 09:57:35 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x( Fixed(0) ), _y ( Fixed(0) ) {};

Point::Point( const float x, const float y ) : _x( Fixed(x) ), _y ( Fixed(y) ) {};

Point::Point( const Point& src ) : _x( src.getX() ), _y( src.getY() ) {};

Point&	Point::operator=(const Point& src)
{
	if (this != &src)
	{
		( Fixed )_x = src.getX();
		( Fixed )_y = src.getY();
	}
	return (*this);
}

Point::~Point ( void ) {}

/* ************************************************************************** */

Fixed	Point::getX( void ) const { return (_x); }

Fixed	Point::getY( void ) const { return (_y); }
