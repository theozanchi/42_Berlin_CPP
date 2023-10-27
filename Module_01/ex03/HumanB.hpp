/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:54:01 by tzanchi           #+#    #+#             */
/*   Updated: 2023/10/27 18:42:41 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanB
{
private:
	std::string	_name;
	Weapon*		_weapon;

public:
	HumanB( std::string name );
	~HumanB();

	void	attack( void );
	void	setWeapon( Weapon& weapon );
};
