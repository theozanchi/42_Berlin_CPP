/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:20:15 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 12:42:23 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Animal
{
protected:
	std::string	type;

public:
	std::string		getType( void ) const;
	virtual void	makeSound( void ) const;

	Animal();
	Animal( const Animal& src );
	Animal& operator=( const Animal& src);
	virtual ~Animal();
};
