/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:25:44 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 13:25:45 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
public:
	void	makeSound( void ) const;

	WrongDog();
	WrongDog( const WrongDog& src );
	WrongDog& operator=( const WrongDog& src );
	~WrongDog();
};