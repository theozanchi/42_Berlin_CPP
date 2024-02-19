/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:38:58 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/19 16:39:38 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

# include <string>
# include <sstream>
# include <cmath>
# include <cstdlib>
# include <cerrno>
# include <limits>

class Parser {
private:
	Parser() {}
	~Parser() {}

public:
	static int		extractDate( const std::string& line, const char del );
	static float	extractValue( const std::string& line, const char del );
	
	static std::pair<int, float>	parseLine( const std::string& line, const char del );
};

#endif
