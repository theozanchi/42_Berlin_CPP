/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:09:55 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 16:26:03 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

/* ************************************************************************** */

void	Dog::makeSound( void ) const {
	std::cout << "Bark sound" << std::endl;
}

/* ************************************************************************** */

Dog::Dog() : A_Animal() { 
	type = "Dog";
	try {
		_brain = new Brain();
	}
	catch(const std::bad_alloc& e) {
		throw e;
	}	
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog( const Dog& src ) : A_Animal( src ) {
	_brain = new Brain();
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=( const Dog& src) {
	if (this != &src) {
		A_Animal::operator=(src);
		delete _brain;
		_brain = new Brain(*(src._brain));
	}
	std::cout << "Dog assignment operator used" << std::endl;
	return (*this);
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}
