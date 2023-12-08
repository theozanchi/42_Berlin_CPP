/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:25:56 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 16:24:11 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Animal.hpp"
#include <iostream>

/* ************************************************************************** */

std::string		A_Animal::getType( void ) const { return type; }

/* ************************************************************************** */

A_Animal::A_Animal() : type( "A_Animal" ) {
	std::cout << "A_Animal constructor called" << std::endl;
}

A_Animal::A_Animal( const A_Animal& src ) : type( src.type ) {
	std::cout << "A_Animal copy constructor called" << std::endl;
}

A_Animal& A_Animal::operator=( const A_Animal& src ) {
	if (this != &src)
		type = src.type;
	std::cout << "A_Animal assignment operator used" << std::endl;
	return (*this);
}

A_Animal::~A_Animal() {
	std::cout << "A_Animal destructor called" << std::endl;
}
