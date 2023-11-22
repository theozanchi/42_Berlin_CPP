/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:39:05 by tzanchi           #+#    #+#             */
/*   Updated: 2023/11/22 21:06:40 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Harl
{
private:
	void	debug( void ) const;
	void	info( void ) const;
	void	warning( void ) const;
	void	error( void ) const;

	struct	FunctionMapping {
		std::string level;
		void (Harl::*function)(void) const;
	};

public:
	Harl( void );
	~Harl();
	void	complain( std::string level );
};
