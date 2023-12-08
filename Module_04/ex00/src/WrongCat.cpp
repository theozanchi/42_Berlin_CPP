/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:23:51 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 13:43:01 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

/* ************************************************************************** */

void	WrongCat::makeSound( void ) const {
	std::cout << "Wrong meow sound" << std::endl;
}

/* ************************************************************************** */

WrongCat::WrongCat() : WrongAnimal() { 
	type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& src ) : WrongAnimal( src ) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=( const WrongCat& src) {
	if (this != &src)
		type = src.type;
	std::cout << "WrongCat assignment operator used" << std::endl;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}
