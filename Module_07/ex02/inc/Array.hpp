/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:57:44 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/08 19:30:20 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

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
	
	T&	operator[]( const unsigned int i );

	unsigned int	size( void ) const;
};

#endif
