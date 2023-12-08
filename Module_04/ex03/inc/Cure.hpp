/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:16:54 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 19:22:07 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "header.hpp"

class Cure : public AMateria
{
public:
	AMateria*	clone( void ) const;

	Cure();
	Cure( const Cure& src );
	Cure& operator=( const Cure& src );
	~Cure();
};
