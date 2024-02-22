/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:54:15 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/22 16:38:55 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <cstdlib>
# include <stack>
# include <iostream>

class RPN {
private:
	std::stack<int>		_stack;

	void	computeTopTwo( const char& op );

public:
	RPN();
	RPN( const RPN& src );
	RPN& operator=( const RPN& src );
	~RPN();

	int		compute( const std::string& str );
};

#endif
