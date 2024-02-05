/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:10:02 by tzanchi           #+#    #+#             */
/*   Updated: 2024/01/31 09:40:54 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <cctype>
# include <limits>
# include <map>
# include <cmath>
# include <cstdlib>
# include <iomanip>

enum variableType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	MIN_INFF,
	PLU_INFF,
	NANF,
	MIN_INF,
	PLU_INF,
	NAND,
	ERROR
};

class ScalarConverter {
private:
	ScalarConverter(); //constructor is private so class is not instanciable
	
	// static std::map <std::string, variableType> specialTypesMap;

	static variableType specialStringType( const std::string& str );
	static variableType	identifyType( const std::string& str);
	
	static char		toChar( const std::string& str );
	static int		toInt( const std::string& str );
	static float	toFloat( const std::string& str );
	static double	toDouble( const std::string& str);

	static void	display( char c );
	static void	display( int i );
	static void	display( float f );
	static void	display( double d );
	static void	displayAll( double n );

public:
	static void	convert( const std::string& str );
};

#endif
