/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:57:44 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/09 15:33:00 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>

template <class T>
class Array {
private:
	unsigned int	_size;	
	T*				_array;

	class OutOfBoundException: public std::exception {
	public:
		const char *what () const throw();
	};

public:
	Array();
	Array( unsigned int n );
	Array( const Array& src );
	Array& operator=( const Array& src );
	~Array();
	
	T&			operator[]( const unsigned int i );
	const T&	operator[]( const unsigned int i ) const ;

	unsigned int	size( void ) const;
};

template <class T>
std::ostream&	operator<<( std::ostream& os, const Array<T>& arr );

#include "Array.tpp"

#endif
