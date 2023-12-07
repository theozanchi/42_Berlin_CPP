/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:57:14 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/07 18:45:11 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

/* ************************************************************************** */

ClapTrap::ClapTrap( void ) : _name( "no_name" ), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "Claptrap default constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name( name ), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "ClapTrap constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& src ) {
	_name = src.getName();
	_hit_points = src.getHitPoints();
	_energy_points = src.getEnergyPoints();
	_attack_damage = src.getAttackDamage();
	std::cout << "ClapTrap copy constructor called for " << _name << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap default destructor called for " << _name << std::endl;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& src ) {
	if (this != &src)
	{
		_name = src.getName();
		_hit_points = src.getHitPoints();
		_energy_points = src.getEnergyPoints();
		_attack_damage = src.getAttackDamage();
	}
	std::cout << "Assignment operator used for " << _name << std::endl;
	return (*this);
}

/* ************************************************************************** */

std::string		ClapTrap::getName( void ) const { return _name; }
unsigned int	ClapTrap::getHitPoints( void ) const { return _hit_points; }
unsigned int	ClapTrap::getEnergyPoints( void ) const { return _energy_points; }
unsigned int	ClapTrap::getAttackDamage( void ) const { return _attack_damage; }

/* ************************************************************************** */

void	ClapTrap::attack( const std::string& target ) {
	if (_energy_points && _hit_points)
	{
		_energy_points--;
		std::cout << "ClapTrap " << _name << " attacks " << target;
		std::cout << ", causing " << _attack_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " does not have energy to attack " << target << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (_hit_points >= amount)
	{
		std::cout << _name << " loses " << amount << " hit points" <<std::endl;
		_hit_points -= amount;
	}
	else
	{
		std::cout << _name << " loses " << _hit_points << " hit points" <<std::endl;
		_hit_points = 0;
	}

	if (!_hit_points)
		std::cout << _name << " died" << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (_energy_points && _hit_points)
	{
		_hit_points += amount;
		_energy_points--;
		std::cout << _name << " repairs itself of " << amount << " points" << std::endl;
	}
}
