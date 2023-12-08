/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:21:36 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 10:08:18 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

/* ************************************************************************** */

DiamondTrap::DiamondTrap( void ) : ClapTrap(), FragTrap(), ScavTrap() {
	_name = "no_name";
	ClapTrap::_name = _name + "_clap_name";

	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;

	std::cout << "DiamondTrap default constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( name ), FragTrap( name ), ScavTrap( name ) {
	_name = name;
	ClapTrap::_name = name + "_clap_name";

	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;

	std::cout << "DiamondTrap constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& src ) : FragTrap( src ), ScavTrap( src ) {
	std::cout << "DiamondTrap copy constructor called for " << _name << std::endl;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& src ) {
	if (this != &src)
	{
		_name = src._name;
		ClapTrap::_name = src.ClapTrap::_name;
		_hit_points = src._hit_points;
		_energy_points = src._energy_points;
		_attack_damage = src._attack_damage;
	}
	std::cout << "DiamondTrap assignment operator used for " << _name << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap default destructor called for " << _name << std::endl;
}

/* ************************************************************************** */

void	DiamondTrap::whoAmI( void ) {
	std::cout << "I am a DiamondTrap with two names: " << _name;
	std::cout << " and " << ClapTrap::_name << std::endl;
}