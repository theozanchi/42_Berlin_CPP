/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:31:55 by tzanchi           #+#    #+#             */
/*   Updated: 2023/10/27 20:18:25 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int	main( int argc, char **argv )
{
	std::fstream	input;
	std::fstream	output;

	if (argc != 4)
	{
		std::cout << "Invalid number arguments: one file name and two strings \
			expected" << std::endl;
		return (EXIT_FAILURE);
	}
	input.open(argv[1], std::fstream::in);
	output.open((std::string)(argv[1] + ".replace"), std::fstream::out)
}
