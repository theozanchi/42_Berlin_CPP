/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:27:35 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/19 15:37:56 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <cmath>
# include <sstream>
# include <cstdlib>

class BitcoinExchange {
private:
	std::map<int, float>	_dataBase;
	char					_delimiter;

	void	parseDataBase( const char* path );
	
public:
	BitcoinExchange( const char* path, const char delimiter );
	BitcoinExchange( const BitcoinExchange& src );
	BitcoinExchange& operator=( const BitcoinExchange& src );
	~BitcoinExchange();

	void	quickDisplay( void ) const;
	void	fullDisplay( void ) const;

	float	getRate( int date) const;
};

#endif
