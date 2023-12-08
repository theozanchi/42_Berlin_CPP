/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:16:59 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 19:23:31 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

/* ************************************************************************** */

AMateria*	Cure::clone( void ) const { return new Cure(*this); }

/* ************************************************************************** */

Cure::Cure() : AMateria( "cure" ) {}

Cure::Cure( const Cure& src ) : AMateria( src ) {}

Cure& Cure::operator=( const Cure& src ) {
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
}

Cure::~Cure() {}
