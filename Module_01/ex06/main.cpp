/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:38:40 by tzanchi           #+#    #+#             */
/*   Updated: 2023/11/24 12:38:09 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main( int argc, char **argv )
{
	Harl		Harl0;
	
	if (argc != 2)
	{
		std::cout << "Two arguments required" << std::endl;
		return (EXIT_FAILURE);
	}

	Harl0.complain(argv[1]);
	return (EXIT_SUCCESS);
}
