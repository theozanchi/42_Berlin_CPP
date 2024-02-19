/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:05:22 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/19 21:08:25 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>

int	main( int argc, char **argv ) {
	if (argc < 3) {
		std::cerr << "Error: enter at least 2 numbers to sort" << std::endl;
		return (EXIT_FAILURE);
	}
	else {
		std::cout << "\033[1;32mTest with vec\033[0m" << std::endl;
		PmergeMe<std::vector<int> >	vec(argc - 1, argv + 1);
		
		vec.sort();
		vec.displayPairs();
		std::cout << std::endl;
		vec.displayContainers();
		std::cout << std::endl;

		return (EXIT_SUCCESS);
	}
}
