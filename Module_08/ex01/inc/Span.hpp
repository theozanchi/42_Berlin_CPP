/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:18:32 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/14 11:11:41 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <cstdlib>
#include <vector>
#include <exception>
#include <string>
#include <sstream>
#include <algorithm>
#include <limits>
#include <ctime>
#include <iostream>

class Span {
private:
	size_t				_capacity;
	std::vector<int>	_vec;

public:
	Span( size_t N );
	Span( const Span& src );
	Span& operator=( const Span& src );
	~Span();

	int				at( size_t i ) const;

	void			addNumber( int n );
	void			fillSpan( void );
	unsigned int	shortestSpan( void ) const;
	unsigned int	longestSpan( void ) const;
};



class CapacityReached : public std::exception {
private:
	std::string	message;

public:
	CapacityReached( const size_t& capacity );
	~CapacityReached() throw() {}
	const char* what() const throw();
};

class SpanTooShort : public std::exception {
public:
	const char* what() const throw();
};

#endif
