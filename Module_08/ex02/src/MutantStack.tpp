/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:36:04 by tzanchi           #+#    #+#             */
/*   Updated: 2024/02/14 12:33:49 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/* Constructors, assignment operator and destructor ************************* */

template <class T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <class T>
MutantStack<T>::MutantStack( const MutantStack<T>& src ) : std::stack<T>( src ) {}

template <class T>
MutantStack<T>& MutantStack<T>::operator=( const MutantStack<T>& src ) {
	if (this != &src) {
		this->c = src.c; 
	}
	return (*this);
}

template <class T>
MutantStack<T>::~MutantStack<T>() {}

/* Iterator ***************************************************************** */

template <class T>
typename MutantStack<T>::iterator	MutantStack<T>::begin() { return (this->c.begin()); }

template <class T>
typename MutantStack<T>::iterator	MutantStack<T>::end() { return (this->c.end()); }

/* Constant iterator ******************************************************** */

template <class T>
typename MutantStack<T>::const_iterator	MutantStack<T>::cbegin() const { return (this->c.cbegin()); }

template <class T>
typename MutantStack<T>::const_iterator	MutantStack<T>::cend() const { return (this->c.cend()); }

/* Reverse iterator ********************************************************* */

template <class T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin() { return (this->c.rbegin()); }

template <class T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend() { return (this->c.rend()); }

/* Constant reverse iterator ************************************************ */

template <class T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::crbegin() const { return (this->c.crbegin()); }

template <class T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::crend() const { return (this->c.crend()); }
