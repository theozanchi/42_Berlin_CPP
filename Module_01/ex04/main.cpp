/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 07:27:58 by tzanchi           #+#    #+#             */
/*   Updated: 2023/11/22 20:34:42 by tzanchi          ###   ########.fr       */
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

std::string	replace_in_string( std::string str, std::string& search, std::string& replace )
{
	std::string::size_type	found = str.find(search);

	if (found == std::string::npos)
		return (str);

	std::string	before = str.substr(0, found);
	std::string	after = replace_in_string(str.substr(found + search.length()), search, replace);

	return (before + replace + after);
}

int	replace( std::ifstream& input_fs, char **argv )
{
	std::ofstream	output_fs;
	std::string		line;
	std::string		search = argv[2];
	std::string		replace = argv[3];

	output_fs.open(new_filename(argv[1]), std::fstream::out);
	if (!output_fs.is_open())
	{
		std::cout << "Error while opening the output file" << std::endl;
		return (EXIT_FAILURE);
	}
	while (getline(input_fs, line))
	{
		output_fs << replace_in_string(line, search, replace) << std::endl;
		if (!output_fs.good())
		{
			std::cout << "Error while writing the output file" << std::endl;
			return (EXIT_FAILURE);
		}
	}
	if (!input_fs.eof() && input_fs.fail())
	{
		std::cout << "Error while reading the input file" << std::endl;
		return (EXIT_FAILURE);
	}
	output_fs.close();
	return (EXIT_SUCCESS);
}

int	main( int argc, char **argv )
{
	std::ifstream	input_fs;
	int				exit_code;

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
	exit_code = replace(input_fs, argv);
	input_fs.close();
	return (exit_code);
}
