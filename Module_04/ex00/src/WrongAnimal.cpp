/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:22:02 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 13:42:37 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

/* ************************************************************************** */

std::string		WrongAnimal::getType( void ) const { return type; }

void	WrongAnimal::makeSound( void ) const {
	std::cout << "Wrong animal sound" << std::endl;
}

/* ************************************************************************** */

WrongAnimal::WrongAnimal() : type( "WrongAnimal" ) {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& src ) : type( src.type ) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& src ) {
	if (this != &src)
		type = src.type;
	std::cout << "WrongAnimal assignment operator used" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}
