/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:54:15 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/22 16:58:27 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <cstdlib>
# include <stack>
# include <iostream>

class RPN {
private:
	RPN() {}
	static void	computeTopTwo( std::stack<int>& stack, const char& op );

public:
	static int		compute( const std::string& str );
};

#endif
