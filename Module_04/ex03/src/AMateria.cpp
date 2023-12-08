/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:32:08 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 19:23:17 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

/* ************************************************************************** */

const std::string&	AMateria::getType( void ) const { return _type; }

void	AMateria::use(ICharacter& target) {
	if (_type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (_type == "cure")
		std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	else {
		std::cout << "* " << target.getName() << "does something with ";
		std::cout << _type << " *" << std::endl;
	}
}

/* ************************************************************************** */
	
AMateria::AMateria() {}

AMateria::AMateria( const std::string& type ) : _type( type ) {}

AMateria::AMateria( const AMateria& src ) : _type( src._type ) {};

AMateria& AMateria::operator=( const AMateria& src ) {
	(void)src;
	return (*this);
}

AMateria::~AMateria() {}
