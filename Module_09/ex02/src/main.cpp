/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:05:22 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/21 19:08:41 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeVec.hpp"
#include "PmergeMeDeq.hpp"

int	main( int argc, char **argv ) {
	if (argc < 3) {
		std::cerr << "Error: enter at least 2 numbers to sort" << std::endl;
		return (EXIT_FAILURE);
	}
	else {
		PmergeMeVec	vec(argc - 1, argv + 1);
		// PmergeMeDeq	deq(argc - 1, argv + 1);
		
		std::cout << "Before:  " << vec << std::endl; 
		vec.sort();
		// deq.sort();
		std::cout << "After:   " << vec << std::endl;
		std::cout << "Time to process a range of " << vec.getSize() << " elements with std::vector: " << vec.getTime() << " us" << std::endl;
		// std::cout << "Time to process a range of " << deq.getSize() << " elements with std::deque:  " << deq.getTime() << " us" << std::endl;

		return (EXIT_SUCCESS);
	}
}
