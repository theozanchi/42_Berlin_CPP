/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:54:12 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/22 16:57:19 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* Member functions ********************************************************* */

void	RPN::computeTopTwo( std::stack<int>& stack, const char& op ) {
	if (stack.empty())
		throw (std::invalid_argument("Error: wrong expression"));
	int	temp2 = stack.top();
	stack.pop();
	if (stack.empty())
		throw (std::invalid_argument("Error: wrong expression"));
	int	temp1 = stack.top();
	stack.pop();

	switch (op) {
		case '+':
			stack.push(temp1 + temp2);
			break;
		case '-':
			stack.push(temp1 - temp2);
			break;
		case '*':
			stack.push(temp1 * temp2);
			break;
		case '/':
			if (temp2 == 0)
				throw (std::invalid_argument("Error: division by zero"));
			stack.push(temp1 / temp2);
			break;
	}
}

bool	isoperand( const char& c ) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int	RPN::compute( const std::string& str ) {
	std::stack<int>	stack;

	for (std::string::const_iterator it = str.begin(); it < str.end(); ++it) {
		if (isdigit(*it))
			stack.push(*it - '0');
		else if (isspace(*it))
			continue;
		else if (isoperand(*it))
			computeTopTwo(stack, *it);
		else
			throw (std::invalid_argument("Error: unexpected symbol"));
	}
	if (stack.size() != 1)
		throw (std::invalid_argument("Error: invalid expression"));
	return (stack.top());
}
