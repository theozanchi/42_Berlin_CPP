/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:18:41 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/14 11:27:01 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* Constructors, assignment operator and destructor ************************* */

Span::Span( size_t N ) : _capacity( N ) {}

Span::Span( const Span& src ) : _capacity( src._capacity ) { _vec = src._vec; }

Span& Span::operator=( const Span& src ) {
	if (this != &src) {
		_capacity = src._capacity;
		_vec = src._vec;
	}
	return (*this);
}

Span::~Span() {}

/* Exceptions *************************************************************** */

CapacityReached::CapacityReached( const size_t& capacity ) {
	std::stringstream	oss;
	oss << "error: capacity of " << capacity << " reached";
	message = oss.str();
}

const char*	CapacityReached::what( void ) const throw() {
	return (message.c_str());
}

const char*	SpanTooShort::what( void ) const throw() {
	return "error: no span, too short";
}

/* Member functions ********************************************************* */

int	Span::at( size_t i ) const {
	return (_vec[i]);
}

void	Span::addNumber( int n ) {
	if (_vec.size() == _capacity)
		throw (CapacityReached(_capacity));
	else
		_vec.push_back(n);
}

int	RandomNumber( void ) { return (std::rand() % 10000); }

void	Span::fillSpan( void ) {
	std::srand( unsigned( std::time(0) ) );
	_vec.clear();
	_vec.reserve(_capacity);
	std::generate_n(std::back_inserter(_vec), _capacity, RandomNumber);
}

unsigned int	Span::shortestSpan( void ) const {
	if (_vec.size() < 2)
		throw (SpanTooShort());

	std::vector<int>	sorted_vec = _vec;
	std::sort(sorted_vec.begin(), sorted_vec.end());
	unsigned int	cur_span = std::numeric_limits<int>::max();
	for (std::vector<int>::const_iterator it = sorted_vec.begin(); it < sorted_vec.end() - 1; ++it) {
		unsigned int diff = abs(*(it + 1) - *it);
		if (diff < cur_span)
			cur_span = diff;
		if (cur_span == 1)
			return (cur_span);
	}
	return (cur_span);
}

unsigned int	Span::longestSpan( void ) const {
	if (_vec.size() < 2)
		throw (SpanTooShort());

	std::vector<int>	sorted_vec = _vec;
	std::sort(sorted_vec.begin(), sorted_vec.end());
	return (abs(sorted_vec.back() - sorted_vec.front()));
}
