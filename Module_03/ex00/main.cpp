/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:57:10 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/07 17:17:30 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main( void )
{
	ClapTrap	alphonse = ClapTrap( "Alphonse" );
	ClapTrap	albert = ClapTrap( "Albert" );
	ClapTrap	somebody;

	alphonse.attack("Albert");
	albert.takeDamage(alphonse.getAttackDamage());
	somebody.beRepaired(10);
	std::cout << somebody.getName() << " has " << somebody.getHitPoints() << " hit points" << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		alphonse.attack("Albert");
		if (alphonse.getEnergyPoints() + 1)
			albert.takeDamage(alphonse.getAttackDamage());
	}
}
