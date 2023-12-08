/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:44:01 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 14:27:11 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
public:
	void	makeSound( void ) const;

	Dog();
	Dog( const Dog& src );
	Dog& operator=( const Dog& src );
	~Dog();
};
