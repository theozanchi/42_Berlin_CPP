/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:20:40 by tzanchi           #+#    #+#             */
/*   Updated: 2023/10/26 18:03:52 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main( int argc, char **argv )
{
	if (argc != 3)
		return (EXIT_FAILURE);

	size_t	N = atoi(argv[1]);
	Zombie	*horde = zombieHorde(N, argv[2]);

	for (size_t i = 0; i < N; ++i)
		horde[i].announce();

	for (int i = 0; i < N; ++i)
		horde[i].~Zombie();

	operator delete[](horde);
}
