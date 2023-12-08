/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:23:07 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 09:31:39 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

/* ************************************************************************** */

ScavTrap::ScavTrap( void ) : ClapTrap() {
	std::cout << "ScavTrap default constructor called for " << _name << std::endl;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name ) {
	std::cout << "ScavTrap constructor called for " << _name << std::endl;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}

ScavTrap::ScavTrap( const ScavTrap& src ) : ClapTrap( src ){
	std::cout << "ScavTrap copy constructor called for " << _name << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap default destructor called for " << _name << std::endl;
}

ScavTrap&	ScavTrap::operator=( const ScavTrap& src ) {
	if (this != &src)
	{
		static_cast<ClapTrap&>(*this) = src;
		std::cout << "ScavTrap assignment operator used for " << _name << std::endl;
    }
    return (*this);
}

/* ************************************************************************** */

void	ScavTrap::attack( const std::string& target ) {
	if (_energy_points && _hit_points)
	{
		_energy_points--;
		std::cout << "ScavTrap " << _name << " attacks " << target;
		std::cout << ", causing " << _attack_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << _name << " does not have energy to attack " << target << std::endl;
}

void	ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode" << std::endl;
}
