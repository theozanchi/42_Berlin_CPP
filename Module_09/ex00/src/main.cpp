/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:22:43 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/19 16:40:47 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Parser.hpp"

#include <iostream>

std::string formatDate(int date) {
	std::stringstream	ss;

	int year = date / 10000;
	int month = (date % 10000) / 100;
	int day = date % 100;

	ss << year << "-";
	if (month < 10) {
		ss << "0";
	}
	ss << month << "-";
	if (day < 10) {
		ss << "0";
	}
	ss << day;

	return ss.str();
}

void	processInputFile( const char *path, const BitcoinExchange& db) {
	std::ifstream			ifs;
	std::string				line;
	std::pair<int, float>	pair;

	ifs.open(path, std::ifstream::in);
	while (std::getline(ifs, line)) {
		if (line == "date | value")
			continue;
		pair = Parser::parseLine(line, '|');
	
		if (pair.first == -1)
			std::cerr << "Error: bad input => " << line.substr(0, line.find('|')) << std::endl;
		else if (std::isnan(pair.second) || pair.second < 0)
			std::cerr << "Error: not a positive number." << std::endl;
		else if (std::isinf(pair.second))
			std::cerr << "Error: too large a number." << std::endl;
		else
			std::cout << formatDate(pair.first) << " => " << pair.second << " = " << pair.second * db.getRate(pair.first) << std::endl;
	}
	ifs.close();
}

int	main( int argc, char **argv ) {
	if (argc != 2) {
		std::cout << "Error: one argument only, path to input file" << std::endl;
		return (EXIT_FAILURE);
	}
	else {
		try {
			BitcoinExchange	db("data.csv", ',');

			processInputFile(argv[1], db);
		}
		catch (const std::invalid_argument& e) {
			std::cerr << e.what() << std::endl;
		}
		
	}
	return (EXIT_SUCCESS);
}
 