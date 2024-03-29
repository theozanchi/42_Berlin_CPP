/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:58:56 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/09 15:48:01 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/* Constructors, assignment operator and destructor ************************* */

template <class T>
Array<T>::Array() : _size( 0 ), _array( NULL ) {}

template <class T>
Array<T>::Array( unsigned int n ) : _size( n ), _array( _size > 0 ? new T[_size] : NULL ) {}

template <class T>
Array<T>::Array( const Array<T>& src ) : _size( src._size ), _array( new T[_size] ) {
	for (unsigned int i = 0; i < _size; ++i) {
		_array[i] = src._array[i];
	}
}

template <class T>
Array<T>& Array<T>::operator=( const Array<T>& src ) {
	if (this != &src) {
		_size = src._size;
		delete[] _array;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; ++i) {
			_array[i] = src._array[i];
		}
	}
	return (*this);
}

template <class T>
Array<T>::~Array() { delete[] _array; }

/* Member functions ********************************************************* */

template <class T>
unsigned int	Array<T>::size( void ) const { return (_size); }

/* Array accessor opeartor overload ***************************************** */

template <class T>
T& Array<T>::operator[]( const unsigned int i ) {
	if (i >= this->size())
		throw OutOfBoundException();
	else
		return (_array[i]);
}

template <class T>
const T& Array<T>::operator[]( const unsigned int i ) const {
	if (i >= this->size())
		throw OutOfBoundException();
	else
		return (_array[i]);
}

/* Exception **************************************************************** */

template<typename T>
const char    *Array<T>::OutOfBoundException::what(void) const throw() {
    return ("error: index out of bound");
}

/* Output operator overload ************************************************* */

template <class T>
std::ostream&	operator<<( std::ostream& os, const Array<T>& arr ) {
	if (!arr.size())
		os << "{ }";
	else {
		os << "{ ";
		for (unsigned int i = 0; i < arr.size() - 1; ++i) {
			os << arr[i] << " , ";
		}
		os << arr[arr.size() - 1] << " }";
	}
	return (os);
}
