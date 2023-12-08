/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:33:12 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 16:24:25 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "A_Animal.hpp"
#include "Brain.hpp"

class Cat : public A_Animal
{
private:
	Brain*	_brain;

public:
	void	makeSound( void ) const;

	Cat();
	Cat( const Cat& src );
	Cat& operator=( const Cat& src);
	~Cat();
};
