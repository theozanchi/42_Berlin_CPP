/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:19:35 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 13:21:15 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class WrongAnimal
{
protected:
	std::string	type;

public:
	std::string		getType( void ) const;
	void			makeSound( void ) const;

	WrongAnimal();
	WrongAnimal( const WrongAnimal& src );
	WrongAnimal& operator=( const WrongAnimal& src);
	~WrongAnimal();
};
