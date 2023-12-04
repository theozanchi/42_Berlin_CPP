/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:34:39 by tzanchi           #+#    #+#             */
/*   Updated: 2023/11/28 21:24:47 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief Check if two fixed-point numbers have the same size
 * 
 * @return true or false
 */
bool	same_sign(Fixed m, Fixed n)
{
	return ((m > 0 && n > 0) || (m < 0 && n < 0) || (m == 0 && n == 0));
}

/**
 * @brief Calculates coefficients A, B and C of the line between a and b of equation
 * A * x + B * y + C = 0. Checks if points m and n are on the same side of the line
 * 
 * @return true or false
 */
bool	same_half_plan(Point const a, Point const b, Point const m, Point const n)
{
	Fixed	A = b.getY() - a.getY();
	Fixed	B = a.getX() - b.getX();
	Fixed	C = Fixed(-1) * (A * a.getX() + B * a.getY());

	return (same_sign(A * m.getX() + B * m.getY() + C,
						A * n.getX() + B * n.getY() + C));
}

/**
 * @brief Check if a point is in a triangle between a, b and c: c and point on the
 * same side of the line between a and b. a and point on same side as b and c and
 * b and point on same side as a and c
 * 
 * @return true or false
 */
bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	return (same_half_plan(a, b, c, point) &&
			same_half_plan(b, c, a, point) &&
			same_half_plan(a, c, b, point));
}
