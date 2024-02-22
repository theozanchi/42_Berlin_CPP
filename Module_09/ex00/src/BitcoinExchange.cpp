/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:27:32 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/22 16:29:17 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Parser.hpp"

/* Constructors, assignment operator and destructor ************************* */

BitcoinExchange::BitcoinExchange( const char* path, const char delimiter ) {
	_delimiter = delimiter;
	parseDataBase(path);
	if (_dataBase.empty())
		throw (std::invalid_argument("error: empty database"));
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& src ) { _dataBase = src._dataBase; }

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& src ) {
	if (this != &src) {
		*this = src;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

/* Public functions ********************************************************* */

void	BitcoinExchange::quickDisplay( void ) const {
	std::cout << "Database of size " << this->_dataBase.size() << std::endl << std::endl;
	
	std::map<int, float>::const_iterator it = this->_dataBase.begin();
	for (size_t i = 0; i < 3 && it != this->_dataBase.end(); ++i, ++it) {
		std::cout << "[ " << i << " ] - Date: " << it->first << ", Rate:" << std::fixed << std::setprecision(2) << it->second << std::endl;
	}

	std::cout << " ... " << std::endl;

	std::map<int, float>::const_reverse_iterator rit = this->_dataBase.rbegin();
	for (size_t i = 0; i < 2 && rit != this->_dataBase.rend(); ++i, ++rit);

	for (size_t i = 0; i < 3 && rit != this->_dataBase.rend(); ++i, --rit) {
		std::cout << "[ " << this->_dataBase.size() - 3 + i << " ] - Date: " << rit->first << ", Rate: " << std::fixed << std::setprecision(2) << rit->second << std::endl;
	}
}

void	BitcoinExchange::fullDisplay( void ) const {
	std::cout << "Database of size " << this->_dataBase.size() << std::endl << std::endl;
	
	std::map<int, float>::const_iterator it = this->_dataBase.begin();
	for (size_t i = 0; it != this->_dataBase.end(); ++i, ++it) {
		std::cout << "[ " << i << " ] - Date: " << it->first << ", Rate:" << std::fixed << std::setprecision(2) << it->second << std::endl;
	}
}

float	BitcoinExchange::getRate( int date ) const {
	if (float rate = _dataBase.find(date)->second)
		return (rate);
	else {
		std::map<int, float>::const_iterator it = _dataBase.begin();
		while (it->first < date && it != _dataBase.end())
			++it;
		if (it == _dataBase.begin())
			return (it->second);
		else
			return ((--it)->second);
	}
}

/* Member functions ********************************************************* */

void	BitcoinExchange::parseDataBase( const char* data_base_path ) {
	std::ifstream			ifs;
	std::string				line;
	std::pair<int, float>	pair;

	ifs.open(data_base_path, std::ifstream::in);
	while (std::getline(ifs, line)) {
		pair = Parser::parseLine(line, _delimiter);
		if (pair.first != -1 && !std::isnan(pair.second))
			_dataBase.insert(pair);
	}
	ifs.close();
}
