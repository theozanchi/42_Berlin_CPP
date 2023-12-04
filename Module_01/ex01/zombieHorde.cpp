/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:10:05 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/04 20:54:16 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde = static_cast<Zombie *>(operator new[](N * sizeof(Zombie)));

	for (int i = 0; i < N; ++i)
		new (&horde[i]) Zombie(name);
	return (horde);
}