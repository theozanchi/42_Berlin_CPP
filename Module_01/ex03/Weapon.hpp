/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:53:32 by tzanchi           #+#    #+#             */
/*   Updated: 2023/10/27 18:32:33 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Weapon
{
private:
	std::string	_type;
	
public:
	Weapon( std::string type );
	Weapon();
	~Weapon();

	const std::string&	getType( void ) const;
	void				setType( std::string new_type );
};
