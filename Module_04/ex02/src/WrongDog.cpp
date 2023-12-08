/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:26:08 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 13:42:46 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"
#include <iostream>

/* ************************************************************************** */

void	WrongDog::makeSound( void ) const {
	std::cout << "Wrong bark sound" << std::endl;
}

/* ************************************************************************** */

WrongDog::WrongDog() : WrongAnimal() { 
	type = "WrongDog";
	std::cout << "WrongDog constructor called" << std::endl;
}

WrongDog::WrongDog( const WrongDog& src ) : WrongAnimal( src ) {
	std::cout << "WrongDog copy constructor called" << std::endl;
}

WrongDog& WrongDog::operator=( const WrongDog& src) {
	if (this != &src)
		type = src.type;
	std::cout << "WrongDog assignment operator used" << std::endl;
	return (*this);
}

WrongDog::~WrongDog() {
	std::cout << "WrongDog destructor called" << std::endl;
}
