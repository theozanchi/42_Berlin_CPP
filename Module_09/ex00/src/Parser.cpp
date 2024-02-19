/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:50:35 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/19 16:40:08 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

int	Parser::extractDate( const std::string& line, const char del ) {
	std::istringstream	iss(line);
	std::string			dateStr;
	std::getline(iss, dateStr, del);

	int					year, month, day;
	char				delimiter;
	std::istringstream	dateStream(dateStr);
	dateStream >> year >> delimiter >> month >> delimiter >> day;

	if (dateStream.fail() || delimiter != '-' || month < 1 || month > 12 || day < 1 || day > 31)
		return (-1);

	if (year < 2009 || year > 2024
		|| (month % 2 == 0  && month < 8 && day > 30)
		|| (month % 2 != 0  && month > 8 && day > 30)
		|| (month == 2 && day > 29))
		return (-1);

	return (year * 10000 + month * 100 + day);
}

float	Parser::extractValue( const std::string& line, const char del ) {
	size_t	del_pos = line.find(del);
	
	if (del_pos == std::string::npos || del_pos == line.length() - 1)
		return (NAN);

	std::string	rateStr = line.substr(del_pos + 1);
	char		*endPtr;
	double		rate = std::strtod(rateStr.c_str(), &endPtr);
	if (*endPtr != '\0')
		return (NAN);
	else if (rate > std::numeric_limits<int>::max())
		return (INFINITY);
	else
		return (rate);
}

std::pair<int, float>	Parser::parseLine( const std::string& line, const char del ) {
	int		date = Parser::extractDate(line, del);
	float	rate = Parser::extractValue(line, del);

	return (std::pair<int, float>(date, rate));
}

