/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:53:52 by tzanchi           #+#    #+#             */
/*   Updated: 2023/10/27 15:09:46 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string	_name;
	Weapon		_weapon;

public:
	HumanA( std::string name, Weapon weapon );
	~HumanA();

	void	attack( void );
};
