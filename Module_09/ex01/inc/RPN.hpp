/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:54:15 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/19 18:06:34 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <stdexcept>
# include <iostream>

class RPN {
private:
	std::stack<int>		_values;
	std::stack<char>	_ops;

	void	computeTopTwo( void );

public:
	RPN();
	RPN( const RPN& src );
	RPN& operator=( const RPN& src );
	~RPN();

	void	fillStacks( const std::string& str );
	int		compute( void );
};

#endif
