/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:53:55 by tzanchi           #+#    #+#             */
/*   Updated: 2023/10/27 18:41:03 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

/* ************************************************************************** */

HumanA::HumanA( std::string name, Weapon weapon ) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA( void )
{
}

/* ************************************************************************** */

void	HumanA::attack( void )
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
