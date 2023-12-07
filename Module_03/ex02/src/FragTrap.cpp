/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:05:35 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/07 19:15:40 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

/* ************************************************************************** */

FragTrap::FragTrap( void ) : ClapTrap() {
	std::cout << "FragTrap default constructor called for " << getName() << std::endl;
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name ) {
	std::cout << "FragTrap default constructor called for " << getName() << std::endl;
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
}

FragTrap::FragTrap( const FragTrap& src ) : ClapTrap( src ) {
	std::cout << "FragTrap copy constructor called for " << getName() << std::endl;
}

FragTrap& FragTrap::operator=( const FragTrap& src ) {
	if (this != &src)
	{
		static_cast<ClapTrap&>(*this) = src;
		std::cout << "FragTrap assignment operator used for " << getName() << std::endl;
	}
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap default destructor called for " << getName() << std::endl;
}

/* ************************************************************************** */

void	FragTrap::highFiveGuys( void ) {
	std::cout << "Positive high five request for " << getName() << std::endl;
}