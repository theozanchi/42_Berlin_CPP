/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:16:56 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 19:23:37 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

/* ************************************************************************** */

AMateria*	Ice::clone( void ) const { return new Ice(*this); }

/* ************************************************************************** */

Ice::Ice() : AMateria( "ice" ) {}

Ice::Ice( const Ice& src ) : AMateria( src ) {}

Ice& Ice::operator=( const Ice& src ) {
	if (this != &src)
		AMateria::operator=(src);
	return (*this);
}

Ice::~Ice() {}
	