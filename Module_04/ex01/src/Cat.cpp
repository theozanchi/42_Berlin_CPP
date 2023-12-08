/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:36:22 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 16:15:40 by tzanchi          ###   ########.fr       */
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
	try {
		_brain = new Brain();
	}
	catch (const std::bad_alloc& e) {
		throw e;
	}
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat( const Cat& src ) : Animal( src ) {
	_brain = new Brain();
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=( const Cat& src) {
	if (this != &src) {
		Animal::operator=(src);
		delete _brain;
		_brain = new Brain(*(src._brain));
	}
	std::cout << "Cat assignment operator used" << std::endl;
	return (*this);
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}
