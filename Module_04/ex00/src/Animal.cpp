/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:25:56 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 12:37:57 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

/* ************************************************************************** */

std::string		Animal::getType( void ) const { return type; }

void	Animal::makeSound( void ) const {
	std::cout << "Unknown sound" << std::endl;
}

/* ************************************************************************** */

Animal::Animal() : type( "Animal" ) {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal( const Animal& src ) : type( src.type ) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=( const Animal& src ) {
	if (this != &src)
		type = src.type;
	std::cout << "Animal assignment operator used" << std::endl;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}
