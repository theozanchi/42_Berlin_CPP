/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:20:40 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/05 12:16:23 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

Zombie*	zombieHorde( int N, std::string name );

int	main( int argc, char **argv )
{
	if (argc != 3)
		return (1);

	int	N = std::atoi(argv[1]);
	Zombie	*horde = zombieHorde(N, argv[2]);

	for (int i = 0; i < N; ++i)
		horde[i].announce();

	for (int i = 0; i < N; ++i)
		horde[i].~Zombie();

	operator delete[](horde);
}
