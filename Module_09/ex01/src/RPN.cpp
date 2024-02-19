/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:54:12 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/19 18:19:13 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* Constructors, assignment operator and destructor ************************* */

RPN::RPN() {}

RPN::RPN( const RPN& src ) { *this = src; }

RPN& RPN::operator=( const RPN& src ) {
	if (this != &src) {
		*this = src;
	}
	return (*this);
}

RPN::~RPN() {}

/* Member functions ********************************************************* */

void	RPN::computeTopTwo( void ) {
	int	temp = _values.top();
	_values.pop();
	
	switch (char op = _ops.top()) {
		case '+':
			// std::cout << _values.top() << " " << op << " " << temp << std::endl;
			_values.top() = temp + _values.top();
			break;
		case '-':
			// std::cout << _values.top() << " " << op << " " << temp << std::endl;
			_values.top() = temp - _values.top();
			break;
		case '*':
			// std::cout << _values.top() << " " << op << " " << temp << std::endl;
			_values.top() = temp * _values.top();
			break;
		case '/':
			// std::cout << _values.top() << " " << op << " " << temp << std::endl;
			_values.top() = temp / _values.top();
			break;
		default:
			throw (std::invalid_argument("Error"));
	}
	_ops.pop();
}

void	RPN::fillStacks( const std::string& str ) {
	for (std::string::const_reverse_iterator rit = str.rbegin(); rit < str.rend(); ++rit) {
		if (isdigit(*rit))
			_values.push(*rit - 48);
		else if (*rit == ' ')
			continue;
		else
			_ops.push(*rit);
	}
}

int	RPN::compute( void ) {
	while (_values.size() != 1)
		computeTopTwo();
	return (_values.top());
}
