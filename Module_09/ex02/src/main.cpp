/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:05:22 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/22 09:41:06 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>
#include <deque>

int	main( int argc, char **argv ) {
	if (argc < 3) {
		std::cerr << "Error: enter at least 2 numbers to sort" << std::endl;
		return (EXIT_FAILURE);
	}
	else {
		PmergeMe<std::vector<int>, std::vector<std::pair<int, int> > >	vector(argc - 1, argv + 1);
		PmergeMe<std::deque<int>, std::deque<std::pair<int, int> > >	deque(argc -1, argv + 1);
		
		std::cout << "Before:  " << vector << std::endl; 
		vector.sort();
		deque.sort();
		std::cout << "After:   " << vector << std::endl;
		std::cout << "Time to process a range of " << vector.getSize() << " elements with std::vector: " << vector.getTime() << " us" << std::endl;
		std::cout << "Time to process a range of " << deque.getSize() << " elements with std::deque:  " << deque.getTime() << " us" << std::endl;

		return (EXIT_SUCCESS);
	}
}
