/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:57:10 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/07 21:25:47 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int	main( void )
{
	DiamondTrap	alphonse = DiamondTrap( "Alphonse" );
	std::cout <<std::endl;
	DiamondTrap	albert = DiamondTrap( "Albert" );
	std::cout <<std::endl;
	DiamondTrap	somebody;
	std::cout <<std::endl;

	alphonse.attack("Albert");
	albert.takeDamage(alphonse.getAttackDamage());
	somebody.beRepaired(10);
	somebody = DiamondTrap("Didier");
	std::cout << somebody.getName() << " has " << somebody.getHitPoints() << " hit points" << std::endl;

	std::cout << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		alphonse.attack("Albert");
		if (alphonse.getEnergyPoints() + 1)
			albert.takeDamage(alphonse.getAttackDamage());
	}
	somebody.highFiveGuys();
}
