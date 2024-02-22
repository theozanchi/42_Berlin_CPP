/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:49:16 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/22 16:52:53 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main( int argc, char **argv ) {
	if (argc != 2) {
		std::cerr << "Error, one arg string only" << std::endl;
		std::cerr << "Ex: \"1 2 + 3 4 - 5 6 * 7 8 /\"" << std::endl;
		return (EXIT_FAILURE);
	}
	else {
		try {
			std::cout << RPN::compute(argv[1]) << std::endl;
			return (EXIT_SUCCESS);
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
			return (EXIT_FAILURE);
		}
	}
}