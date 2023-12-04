/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:34:32 by tzanchi           #+#    #+#             */
/*   Updated: 2023/11/28 21:21:59 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool	bsp( Point const a, Point const b, Point const c, Point const point );

std::string	printBsp( Point const a, Point const b, Point const c, Point const point )
{
	if (bsp(a, b, c, point) == true)
		return ("true");
	else
		return ("false");
}

int main ( void ) {

	Point const a(0, 0);
	Point const b(6, 0);
	Point const c(3, 6);

	std::cout << "TRIANGLE BETWEEN (0,0), (10,0) and (5, 10)" << std::endl <<std::endl;

	std::cout << "TEST 1: (5,5) - inside" << std::endl;
	std::cout << "Algo outputs " << printBsp(a, b, c, Point(5, 5)) << ", true expected" << std::endl << std::endl;

	std::cout << "TEST 2: (20,20) - outside" << std::endl;
	std::cout << "Algo outputs " << printBsp(a, b, c, Point(20, 20)) << ", false expected" << std::endl << std::endl;

	std::cout << "TEST 3: (5, 0) - on edge" << std::endl;
	std::cout << "Algo outputs " << printBsp(a, b, c, Point(5, 0)) << ", false expected" << std::endl << std::endl;
	
	std::cout << "TEST 4: (0, 0) - on vertex" << std::endl;
	std::cout << "Algo outputs " << printBsp(a, b, c, Point(0, 0)) << ", false expected" << std::endl << std::endl;

	return (0);
}