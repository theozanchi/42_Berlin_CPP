/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:53:45 by tzanchi           #+#    #+#             */
/*   Updated: 2023/10/27 15:11:05 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/* ************************************************************************** */

Weapon::Weapon( std::string type )
{
	_type = type;
}

Weapon::~Weapon( void )
{
}

/* ************************************************************************** */

const std::string&	Weapon::getType( void ) const
{
	return (_type);
}

void	Weapon::setType( std::string type )
{
	_type = type;
}
