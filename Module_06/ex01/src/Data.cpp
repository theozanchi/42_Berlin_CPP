/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:36:21 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/05 16:48:57 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

/* Constructors, assignment operator and destructor ************************* */

Data::Data( int value ) : _value( value ) {}

Data::Data( const Data& src ) : _value( src._value ) {}

Data& Data::operator=( const Data& src ) {
	if (this != &src) {
		_value = src._value;
	}
	return (*this);
}

Data::~Data() {}

/* Accessors **************************************************************** */

const int&	Data::getValue( void ) const { return _value; }
