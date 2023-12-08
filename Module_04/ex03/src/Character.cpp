/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:14:44 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 20:30:40 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

/* ************************************************************************** */

const std::string&	Character::getName() const { return _name; }

void	Character::equip(AMateria* m) {
	size_t	i = 0;

	while (i < 4 && _inventory[i])
		i++;

	if (i < 4) {
		_inventory[i] = m;
		std::cout << "Equiping " << _name << " with " << m->getType();
		std::cout << " at index " << i << std::endl;
	}
}

void	Character::unequip(int idx) {
	if (idx < 4 && _inventory[idx]) {
		_oldMateria[_oldMateriaIndex++] = _inventory[idx];
		_inventory[idx] = NULL;
		std::cout << "Unequiping " << _name << " from ";
		std::cout << _oldMateria[_oldMateriaIndex - 1]->getType();
		std::cout << " at index " << idx << std::endl;
	}
	else if (idx >= 4)
		std::cout << idx << " is not a valid index";
	else
		std::cout << "No equipment at index " << idx << " for " << _name << std::endl; 
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 4 && _inventory[idx]) {
		_inventory[idx]->use(target);
	}
	else if (idx >= 4)
		std::cout << idx << " is not a valid index";
	else
		std::cout << "No equipment at index " << idx << " for " << _name << std::endl; 
}

/* ************************************************************************** */

Character::Character() : _name ( "no_name" ), _oldMateriaIndex( 0 ) {
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (size_t i = 0; i < 1024; i++)
		_oldMateria[i] = NULL;
}

Character::Character( std::string name ) : _name ( name ), _oldMateriaIndex( 0 ) {
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character( const Character& src ) : _name( src._name ) {
	for (size_t i = 0; src._inventory[i] ; i++)
		_inventory[i] = src._inventory[i]->clone();
}

Character& Character::operator=( const Character& src ) {
	if (this != &src) {
		_name = src._name;
		{
			for (size_t i = 0; i < 4; i++) {
				if (_inventory[i]) {
					delete _inventory[i];
				}
			}
			for (size_t i = 0; src._inventory[i] ; i++) {
				_inventory[i] = src._inventory[i]->clone();
			}
		}
		{
			for (size_t i = 0; i < _oldMateriaIndex; i++) {
				delete _oldMateria[i];
			}
			_oldMateriaIndex = src._oldMateriaIndex;
			for (size_t i = 0; _oldMateriaIndex; i++) {
				_oldMateria[i] = src._oldMateria[i]->clone();
			}
			for (size_t i = _oldMateriaIndex; i < 1024 && _oldMateria[i] != NULL; i++) {
				_oldMateria[i] = NULL;
			}
		}
	}
	return (*this);
}

Character::~Character() {
	for (size_t i = 0; i < 4; i++) {
		if (_inventory[i]) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	for (size_t i = 0; i < _oldMateriaIndex; i++) {
		delete _oldMateria[i];
		_oldMateria[i] = NULL;
	}
}
