/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:15:18 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 19:22:40 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "header.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria*	_inventory[4];
	size_t		_index;

public:
	void		learnMateria(AMateria*);
	AMateria*	createMateria(std::string const & type);

	MateriaSource();
	MateriaSource( const MateriaSource& src );
	MateriaSource& operator=( const MateriaSource& src );
	~MateriaSource();
};
