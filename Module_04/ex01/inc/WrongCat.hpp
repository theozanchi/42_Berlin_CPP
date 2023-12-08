/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:22:43 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 13:22:43 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	void	makeSound( void ) const;

	WrongCat();
	WrongCat( const WrongCat& src );
	WrongCat& operator=( const WrongCat& src);
	~WrongCat();
};