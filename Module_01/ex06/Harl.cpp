/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:38:57 by tzanchi           #+#    #+#             */
/*   Updated: 2023/11/22 21:12:03 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

/* private ******************************************************************* */

void	Harl::debug( void ) const
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple"
	"-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info( void ) const
{
	std::cout << "I cannot believe adding extra bacon costs more money. You "
	"didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for "
	"more!" << std::endl;
}

void	Harl::warning( void ) const
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve "
	"been coming for years whereas you started working here since last month.";
	std::cout << std::endl;
}

void	Harl::error( void ) const
{
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

/* public ******************************************************************** */

void	Harl::complain( std::string level )
{
	FunctionMapping mapping[] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};

	for (size_t i = 0; i < 4; i++)
	{
		if (mapping[i].level == level)
		{
			(this->*(mapping[i].function))();
			return ;
		}
	}

	std::cout << level << " is not a valid Harl level" << std::endl;
}

Harl::Harl( void )
{
}

Harl::~Harl()
{
}
