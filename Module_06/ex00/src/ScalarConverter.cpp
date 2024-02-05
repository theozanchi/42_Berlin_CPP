/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:09:59 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/05 10:35:57 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* Maps ********************************************************************* */

// std::map <std::string, variableType> ScalarConverter::specialTypesMap;

ScalarConverter::ScalarConverter() {
	// specialTypesMap.insert(std::make_pair("-inff", MIN_INFF));
	// specialTypesMap.insert(std::make_pair("+inff", PLU_INFF));
	// specialTypesMap.insert(std::make_pair("nanf", NANF));
	// specialTypesMap.insert(std::make_pair("-inf", MIN_INF));
	// specialTypesMap.insert(std::make_pair("+inf", PLU_INF));
	// specialTypesMap.insert(std::make_pair("nan", NAND));
}

/* Converters *************************************************************** */

char ScalarConverter::toChar( const std::string& str ) {
	return (str.at(0));
}

int ScalarConverter::toInt( const std::string& str ) {
	try {
		return (atoi(str.c_str()));
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (0);
	}
}

float ScalarConverter::toFloat( const std::string& str ) {
	try {
		if (str == "-inff")
			return (-INFINITY);
		else if (str == "+inff")
			return (INFINITY);
		else if (str == "nanf")
			return (NAN);
		else
			return (atof(str.c_str()));
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (0.0f);
	}
}

double ScalarConverter::toDouble( const std::string& str) {
	try {
		if (str == "-inf")
			return (-INFINITY);
		else if (str == "+inf")
			return (INFINITY);
		else if (str == "nan")
			return (NAN);
		else
			return (strtod(str.c_str(), NULL));
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (0.0);
	}
}

/* Conversion *************************************************************** */

void	ScalarConverter::convert( const std::string& str ) {
	switch (identifyType(str)) {
		case CHAR: {
			char variable = toChar(str);
			displayAll(variable);
			break;
		}
		case INT: {
			int variable = toInt(str);
			displayAll(variable);
			break;
		}
		case FLOAT:
		case MIN_INFF:
		case PLU_INFF:
		case NANF: {
			float variable = toFloat(str);
			displayAll(variable);
			break;
		}
		case DOUBLE:
		case MIN_INF:
		case PLU_INF:
		case NAND: {
			double variable = toDouble(str);
			displayAll(variable);
			break;
		}
		case ERROR:{
			std::cerr << "Error: impossible to identify type" << std::endl;
		}
	}
}

/* Type identification ****************************************************** */

bool isAlphaString( const std::string& str ) {
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
		if (!isalpha(*it))
			return (false);
	}
	return (true);
}

bool isANumber( const std::string& str ) {
	size_t	dot_counter = 0;
	
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
		if ((*it == '+' || *it == '-') && it != str.begin())
			return (false);
		if (!isdigit(*it)) {
			if (*it == '.') {
				if (++dot_counter > 1)
					return (false);
				continue;
			}
			return (false);
		}
		else if (it == str.end() - 1 && *it == 'f')
			return (true);
	}
	return (true);
}

variableType ScalarConverter::specialStringType( const std::string& str ) {
	std::map <std::string, variableType> specialTypesMap;
	specialTypesMap.insert(std::make_pair("-inff", MIN_INFF));
	specialTypesMap.insert(std::make_pair("+inff", PLU_INFF));
	specialTypesMap.insert(std::make_pair("nanf", NANF));
	specialTypesMap.insert(std::make_pair("-inf", MIN_INF));
	specialTypesMap.insert(std::make_pair("+inf", PLU_INF));
	specialTypesMap.insert(std::make_pair("nan", NAND));
	
	std::map <std::string, variableType>::const_iterator it = specialTypesMap.find(str);
	if (it != specialTypesMap.end())
		return (it->second);
	else
		return (ERROR);
}

variableType	ScalarConverter::identifyType( const std::string& str ) {
	if (str.length() == 1 && str.at(0) >= 0 && str.at(0) <= 127)
		return (CHAR);
	else if (isAlphaString(str))
		return (specialStringType(str));
	else if (isANumber(str)) {
		if (str.at(str.length() - 1) == 'f')
			return (FLOAT);
		else if (str.find('.') != std::string::npos)
			return (DOUBLE);
		else {
			try {
				double n = strtod(str.c_str(), NULL);
				if (n >= std::numeric_limits<int>::min() && n <= std::numeric_limits<int>::max())
					return (INT);
				else
					return (DOUBLE);
			}
			catch (const std::exception& e) {
				std::cerr << e.what() << std::endl;
				return (ERROR);
			}
		}
	}
	else
		return (ERROR);
}

/* Display functions ******************************************************** */

void	ScalarConverter::display( char c ) {
	std::cout << "char: ";

	if (c < 32 || c > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

void	ScalarConverter::display( int i ) {
	std::cout << "int: " << i << std::endl;
}

void	ScalarConverter::display( float f ) {
	std::cout << "float: " << f;
	if (std::abs(f - static_cast<int>(f)) > 0.0f)
		std::cout << "f" << std::endl;
	else
		std::cout << ".0f" << std::endl;
}

void	ScalarConverter::display( double d ) {
	std::cout << "double: " << d;
	if (std::abs(d - static_cast<int>(d)) > 0.0)
		std::cout << std::endl;
	else
		std::cout << ".0" << std::endl;
}

void	ScalarConverter::displayAll( double n ) {
	{
		if (n < std::numeric_limits<char>::min() || n > std::numeric_limits<char>::max())
			std::cout << "char: impossible" << std::endl;
		else
			display(static_cast<char>(n));
	}
	{
		if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
			std::cout << "int: impossible" << std::endl;
		else
			display(static_cast<int>(n));
	}
	{
		if (n < std::numeric_limits<float>::min() || n > std::numeric_limits<float>::max())
			std::cout << "float: impossible" << std::endl;
		else
			display(static_cast<float>(n));
	}
	display(n);
}
