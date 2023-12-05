/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:54:03 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/04 21:01:29 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

/* ************************************************************************** */

HumanB::HumanB( std::string name ) : _name(name), _weapon(nullptr) {}

HumanB::~HumanB( void ) {}

/* ************************************************************************** */

void	HumanB::attack( void )
{
	if (_weapon)
	{
		std::cout << _name << " attacks with their " << _weapon->getType();
		std::cout << std::endl;
	}
	else
		std::cout << _name << " does not attack, no weapon" << std::endl;
}

void	HumanB::setWeapon( Weapon& weapon )
{
	_weapon = &weapon;
}
