/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:09:55 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 11:15:10 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

/* ************************************************************************** */

void	Dog::makeSound( void ) const {
	std::cout << "Bark sound" << std::endl;
}

/* ************************************************************************** */

Dog::Dog() : Animal() { 
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog( const Dog& src ) : Animal( src ) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=( const Dog& src) {
	if (this != &src)
		type = src.type;
	std::cout << "Dog assignment operator used" << std::endl;
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}
