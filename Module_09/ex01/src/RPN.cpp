/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:54:12 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/19 18:55:29 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* Constructors, assignment operator and destructor ************************* */

RPN::RPN() {}

RPN::RPN( const RPN& src ) { _stack = src._stack; }

RPN& RPN::operator=( const RPN& src ) {
	if (this != &src) {
		_stack = src._stack;
	}
	return (*this);
}

RPN::~RPN() {}

/* Member functions ********************************************************* */

void	RPN::computeTopTwo( const char& op ) {
	int	temp2 = _stack.top();
	_stack.pop();
	int	temp1 = _stack.top();
	_stack.pop();

	switch (op) {
		case '+':
			_stack.push(temp1 + temp2);
			break;
		case '-':
			_stack.push(temp1 - temp2);
			break;
		case '*':
			_stack.push(temp1 * temp2);
			break;
		case '/':
			if (temp2 == 0)
				throw (std::invalid_argument("Error: division by zero"));
			_stack.push(temp1 / temp2);
			break;
	}
}

bool	isoperand( const char& c ) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int	RPN::compute( const std::string& str ) {
	for (std::string::const_iterator it = str.begin(); it < str.end(); ++it) {
		if (isdigit(*it))
			_stack.push(*it - '0');
		else if (isspace(*it))
			continue;
		else if (isoperand(*it))
			computeTopTwo(*it);
		else
			throw (std::invalid_argument("Error: unexpected symbol"));
	}
	if (_stack.size() != 1)
		throw (std::invalid_argument("Error: invalid expression"));
	return (_stack.top());
}
