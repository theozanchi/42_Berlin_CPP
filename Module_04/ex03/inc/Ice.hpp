/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:16:52 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 19:22:16 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "header.hpp"

class Ice : public AMateria
{
public:
	AMateria*	clone( void ) const;

	Ice();
	Ice( const Ice& src );
	Ice& operator=( const Ice& src );
	~Ice();
};
