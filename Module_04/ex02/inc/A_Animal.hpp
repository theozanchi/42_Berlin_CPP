/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:20:15 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 16:23:23 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class A_Animal
{
protected:
	std::string	type;

public:
	std::string		getType( void ) const;
	virtual void	makeSound( void ) const = 0;

	A_Animal();
	A_Animal( const A_Animal& src );
	A_Animal& operator=( const A_Animal& src);
	virtual ~A_Animal();
};
