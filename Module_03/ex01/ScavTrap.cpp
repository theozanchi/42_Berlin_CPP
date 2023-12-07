/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:23:07 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/07 18:53:35 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

/* ************************************************************************** */

ScavTrap::ScavTrap( void ) : ClapTrap() {
	std::cout << "ScavTrap default constructor called for " << getName() << std::endl;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name ) {
	std::cout << "ScavTrap constructor called for " << getName() << std::endl;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}

ScavTrap::ScavTrap( const ScavTrap& src ) : ClapTrap( src ){
	std::cout << "ScavTrap copy constructor called for " << getName() << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap default destructor called for " << getName() << std::endl;
}

ScavTrap&	ScavTrap::operator=( const ScavTrap& src ) {
	if (this != &src)
	{
		static_cast<ClapTrap&>(*this) = src;
		std::cout << "ScavTrap assignment operator used for " << getName() << std::endl;
    }
    return (*this);
}

/* ************************************************************************** */

void	ScavTrap::attack( const std::string& target ) {
	if (getEnergyPoints() && getHitPoints())
	{
		_energy_points--;
		std::cout << "ScavTrap " << getName() << " attacks " << target;
		std::cout << ", causing " << _attack_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << getName() << " does not have energy to attack " << target << std::endl;
}

void	ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode" << std::endl;
}
