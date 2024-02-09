/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:57:35 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/09 13:17:22 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main( void ) {
	{
		std::cout << "\033[1;32mTest 1\033[0m: eval sheet test" << std::endl;
		int*	a = new int();
		std::cout << a << std::endl;
	}
	{
		std::cout << std::endl << "\033[1;32mTest 1\033[0m: empty int array" << std::endl;
		Array<int>	empty;
		std::cout << empty << std::endl;
	}
	{
		std::cout << std::endl << "\033[1;32mTest 2\033[0m: int array of size 2" << std::endl;
		Array<int>	arr1(2);
		arr1[0] = 42;
		arr1[1] = 24;
		std::cout << arr1 << std::endl;
	}
	{
		std::cout << std::endl << "\033[1;32mTest 3\033[0m: out of bound access" << std::endl;
		try {
			std::cout << arr1[2] << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
