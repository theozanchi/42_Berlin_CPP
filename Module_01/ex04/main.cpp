/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 07:27:58 by tzanchi           #+#    #+#             */
/*   Updated: 2023/11/01 08:32:56 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

std::string	new_filename( std::string filename )
{
	size_t	last_dot = filename.rfind('.');

	if (last_dot != std::string::npos)
		return (filename.substr(0, last_dot) + ".replace");
	else
		return (filename + ".replace");
}

int	replace( std::ifstream input, char **argv )
{
	std::ofstream	output_fs;

	output_fs.open(new_filename(argv[1]), std::fstream::out);
	if (!output_fs.is_open())
	{
		std::cout << "Error while opening the output file" << std::endl;
		return (EXIT_FAILURE);
	}
}

int	main( int argc, char **argv )
{
	std::ifstream	input_fs;
	std::string		line;

	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (EXIT_FAILURE);
	}
	input_fs.open(argv[1], std::fstream::in);
	if (!input_fs.is_open())
	{
		std::cout << "Error while opening the input file" << std::endl;
		return (EXIT_FAILURE);
	}
	if (replace(input_fs, argv))
		return (EXIT_FAILURE);
	input_fs.close();
	return (EXIT_SUCCESS);
}
