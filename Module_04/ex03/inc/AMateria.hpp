/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:32:06 by tzanchi           #+#    #+#             */
/*   Updated: 2023/12/08 19:21:50 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <header.hpp>

class AMateria
{
protected:
	std::string	_type;

public:
	const std::string&	getType( void ) const;

	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
	
	AMateria();
	AMateria( const std::string& type );
	AMateria( const AMateria& src );
	AMateria& operator=( const AMateria& src );
	virtual ~AMateria();
};