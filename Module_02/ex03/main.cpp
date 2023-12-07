/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:34:32 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/07 17:21:28 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool	bsp( Point const a, Point const b, Point const c, Point const point );

int main()
{
	Point const a(0, 0);
	Point const b(6, 0);
	Point const c(3, 6);

	std::cout << "TRIANGLE BETWEEN (0,0), (6,0) and (3,6)" << std::endl << std::endl;

	std::cout << "TEST 1: (3,4) - inside" << std::endl;
	std::cout << "Algo outputs " << (bsp(a, b, c, Point(3, 4)) ? "true" : "false") << ", true expected" << std::endl << std::endl;

	std::cout << "TEST 2: (10,10) - outside" << std::endl;
	std::cout << "Algo outputs " << (bsp(a, b, c, Point(10, 10)) ? "true" : "false") << ", false expected" << std::endl << std::endl;

	std::cout << "TEST 3: (4, 0) - on edge" << std::endl;
	std::cout << "Algo outputs " << (bsp(a, b, c, Point(4, 0)) ? "true" : "false") << ", false expected" << std::endl << std::endl;

	std::cout << "TEST 4: (6, 0) - on vertex" << std::endl;
	std::cout << "Algo outputs " << (bsp(a, b, c, Point(6, 0)) ? "true" : "false") << ", false expected" << std::endl << std::endl;

	return (0);
}