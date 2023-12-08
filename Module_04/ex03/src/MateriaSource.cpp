/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:15:23 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 20:21:30 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

/* ************************************************************************** */

void	MateriaSource::learnMateria(AMateria* src) {
	if (_index < 4) {
		_inventory[_index++] = src;
		std::cout << src->getType() << " type has been learned" << std::endl;
	}
}

AMateria*	MateriaSource::createMateria(const std::string& type) {
	if (_index) {
		for (size_t i = 0; i < _index; i++) {
			if (_inventory[i]->getType() == type) {
				std::cout << "Creating " << type << std::endl;
				return (_inventory[i]->clone());
			}
		}
		std::cout << "Cannot create materia " << type << ", type unknown" << std::endl;
	}
	std::cout << "Cannot create materia " << type << ", no inventory" << std::endl;
	return (NULL);
}

/* ************************************************************************** */

MateriaSource::MateriaSource( void ) : _index( 0 ) {
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource& src ) {
	if (src._index) {
		_index = src._index;
		for (size_t i = 0; i < _index; i++)
			_inventory[i] = src._inventory[i]->clone();
	}
	
	for (size_t i = _index; i < 4; i++)
		_inventory[i] = NULL;
}

MateriaSource& MateriaSource::operator=( const MateriaSource& src ) {
	if (this != &src) {
		for (size_t i = 0; i < _index; i++)
			delete _inventory[i];
			
		_index = src._index;
		for (size_t i = 0; i < _index; i++)
			_inventory[i] = src._inventory[i]->clone();
		
		for (size_t i = _index; i < 4; i++)
			_inventory[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	if (_index) {
		for (size_t i = 0; i < _index; i++)
			delete _inventory[i];
	}
}
	