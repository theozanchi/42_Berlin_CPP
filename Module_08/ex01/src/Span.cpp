/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:18:41 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/14 10:58:31 by tzanchi          ###   ########.fr       */
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

void	Span::addNumber( int n ) {
	if (_vec.size() == _capacity)
		throw (CapacityReached(_capacity));
	else
		_vec.push_back(n);
}

int	RandomNumber( void ) { return (std::rand() % 100); }

void	Span::fillSpan( void ) {
	std::srand( unsigned( std::time(0) ) );
	std::generate(_vec.begin(), _vec.end(), RandomNumber);
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

/* Redirection operator overload ******************************************** */

// std::ostream&	operator<<(std::ostream& os, const Span& src) {
// 	if (src._capacity < 4) {
		
// 	}
// 	else {
// 		os << "{ 0: " << src._vec[0] << std::endl;
// 		os << "{ 0: " << src._vec[1] << std::endl;

// 		os << "{ 0: " << src._vec[0] << std::endl;
// 		os << "{ 0: " << src._vec[_capacity - 1] << std::endl;
// 	}
// }
