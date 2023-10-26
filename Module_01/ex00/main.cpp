/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:20:40 by tzanchi           #+#    #+#             */
/*   Updated: 2023/10/26 12:49:49 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int	main( void )
{
	Zombie	*zombie_1;
	
	zombie_1 = newZombie("Jean-Pierre");
	zombie_1->announce();
	randomChump("Didier");
	delete zombie_1;
}