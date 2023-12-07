/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:57:12 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/07 18:00:14 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class ClapTrap
{
private:
	std::string		_name;
	unsigned int	_hit_points;
	unsigned int	_energy_points;
	unsigned int	_attack_damage;

public:
	ClapTrap( void );
	ClapTrap( std::string name );
	ClapTrap( const ClapTrap& src );
	~ClapTrap();
	ClapTrap& operator=( const ClapTrap& src );

	std::string		getName( void ) const;
	void				setName( std::string );
	unsigned int	getHitPoints( void ) const;
	void				setHitPoints( unsigned int hit_points );
	unsigned int	getEnergyPoints( void ) const;
	void				setEnergyPoints( unsigned int energy_points );
	unsigned int	getAttackDamage( void ) const;
	void				setAttackDamage( unsigned int attack_damage );

	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );
};
