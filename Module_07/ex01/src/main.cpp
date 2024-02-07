/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:44:36 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/07 18:55:24 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#include <iostream>

int	times_two(int i) { return (2 * i); }

std::string	answer_42(std::string str) {
	(void)str;
	return ("42");
}

int	main( void ) {
	int			arr1[3] = {1, 2, 3};
	std::string	arr2[3] = {"hey", "hello", "world"};

	iter(arr1, 3, times_two);
	iter(arr2, 3, answer_42);
	
	for (int i = 0; i < 3; ++i) {
		std::cout << arr1[i] << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < 3; ++i) {
		std::cout << arr2[i] << std::endl;
	}
}
