/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:36:22 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 11:59:43 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

/* ************************************************************************** */

void	Cat::makeSound( void ) const {
	std::cout << "Meow sound" << std::endl;
}

/* ************************************************************************** */

Cat::Cat() : Animal() { 
	type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat( const Cat& src ) : Animal( src ) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=( const Cat& src) {
	if (this != &src)
		type = src.type;
	std::cout << "Cat assignment operator used" << std::endl;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}
